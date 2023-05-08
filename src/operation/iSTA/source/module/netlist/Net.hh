/**
 * @file Net.h
 * @author simin tao (taosm@pcl.ac.cn)
 * @brief The class for Net in the netlist.
 * @version 0.1
 * @date 2021-02-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <memory>
#include <utility>

#include "Config.hh"
#include "DesignObject.hh"
#include "DisallowCopyAssign.hh"
#include "Type.hh"
#include "Vector.hh"

namespace ista {

class NetPinIterator;
class Pin;
class LibetyCurrentData;

/**
 * @brief The class for net of design.
 *
 */
class Net : public DesignObject {
 public:
  explicit Net(const char *name);
  ~Net() override = default;
  Net(Net &&other) noexcept;
  Net &operator=(Net &&rhs) noexcept;

  friend NetPinIterator;

  unsigned isNet() override { return 1; }

  void addPinPort(DesignObject *pin) {
    _pin_ports.push_back(pin);
    pin->set_net(this);

    std::ranges::for_each(_net_loads,
                          [](auto &net_load) { net_load = std::nullopt; });
  }

  void removePinPort(DesignObject *pin) {
    auto *it = std::find(_pin_ports.begin(), _pin_ports.end(), pin);
    if (it != _pin_ports.end()) {
      _pin_ports.erase(it);
      pin->set_net(nullptr);
    }

    std::ranges::for_each(_net_loads,
                          [](auto &net_load) { net_load = std::nullopt; });
  }

  bool isNetPinPort(DesignObject *pin) {
    auto *it = std::find(_pin_ports.begin(), _pin_ports.end(), pin);
    return it != _pin_ports.end();
  }

  Vector<DesignObject *> &get_pin_ports() { return _pin_ports; }

  DesignObject *getDriver();
  std::vector<DesignObject *> getLoads();
  unsigned getFanouts() { return getLoads().size(); }
  DesignObject *get_pin_port(const char *pin_port_name);

  void set_is_clock_net() { _is_clock_net = true; }
  [[nodiscard]] auto isClockNet() const { return _is_clock_net; }

  double getLoad(AnalysisMode mode, TransType trans_type);

  std::string getFullName() override { return get_name(); }

  int getNetLoadIndex(AnalysisMode mode, TransType trans_type) {
    auto index =
        (mode == AnalysisMode::kMax)
            ? ((trans_type == TransType::kRise) ? ModeTransIndex::kMaxRise
                                                : ModeTransIndex::kMaxFall)
            : ((trans_type == TransType::kRise) ? ModeTransIndex::kMinRise
                                                : ModeTransIndex::kMinFall);
    return static_cast<int>(index);
  }

  auto get_net_load(AnalysisMode mode, TransType trans_type) {
    int index = getNetLoadIndex(mode, trans_type);
    return _net_loads[index];
  }

  void setNetLoad(AnalysisMode mode, TransType trans_type, double load) {
    int index = getNetLoadIndex(mode, trans_type);
    _net_loads[index] = load;
  }

 private:
  Vector<DesignObject *> _pin_ports;
  std::array<std::optional<double>, 4>
      _net_loads{};  //!< store the net loads for quickly calc.
  bool _is_clock_net = false;

  DISALLOW_COPY_AND_ASSIGN(Net);
};

/**
 * @brief The class interator of pin.
 *
 */
class NetPinIterator {
 public:
  explicit NetPinIterator(Net *net);
  ~NetPinIterator() = default;

  bool hasNext();
  DesignObject *next();

 private:
  Net *_net;
  Vector<DesignObject *>::iterator _iter;

  DISALLOW_COPY_AND_ASSIGN(NetPinIterator);
};

/**
 * @brief usage:
 * Net* net;
 * DesignObject * pin_port;
 * FOREACH_NET_PIN(net, pin_port)
 * {
 *    do_something_for_pin();
 * }
 *
 */
#define FOREACH_NET_PIN(net, pin_port) \
  for (NetPinIterator iter(net);       \
       iter.hasNext() ? pin_port = (iter.next()), true : false;)

}  // namespace ista
