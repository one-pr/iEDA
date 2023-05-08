#pragma once

namespace irt {

class PAConfig
{
 public:
  PAConfig() = default;
  ~PAConfig() = default;

  std::string temp_directory_path;
  irt_int bottom_routing_layer_idx = -1;
  irt_int top_routing_layer_idx = -1;
};

}  // namespace irt