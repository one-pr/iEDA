// ***************************************************************************************
// Copyright (c) 2023-2025 Peng Cheng Laboratory
// Copyright (c) 2023-2025 Institute of Computing Technology, Chinese Academy of Sciences
// Copyright (c) 2023-2025 Beijing Institute of Open Source Chip
//
// iEDA is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
// http://license.coscl.org.cn/MulanPSL2
//
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
//
// See the Mulan PSL v2 for more details.
// ***************************************************************************************
#pragma once

#include "AccessPointType.hpp"
#include "EXTLayerCoord.hpp"
#include "RTU.hpp"

namespace irt {

class AccessPoint : public EXTLayerCoord
{
 public:
  AccessPoint() = default;
  AccessPoint(irt_int real_x, irt_int real_y, irt_int layer_idx, AccessPointType type)
  {
    set_real_coord(real_x, real_y);
    set_layer_idx(layer_idx);
    _type = type;
  }
  ~AccessPoint() = default;
  // getter
  AccessPointType get_type() const { return _type; }
  // setter
  void set_type(const AccessPointType& type) { _type = type; }
  // function

 private:
  AccessPointType _type = AccessPointType::kNone;
};

}  // namespace irt
