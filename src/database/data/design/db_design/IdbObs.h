#pragma once
/**
 * iEDA
 * Copyright (C) 2021  PCL
 *
 * This program is free software;
 *
 */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @project		iDB
 * @file		IdbObs.h
 * @copyright	(c) 2021 All Rights Reserved.
 * @date		25/05/2021
 * @version		0.1
 * @description


        Describe Obstrction information,.
 *
 */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../../../basic/geometry/IdbGeometry.h"
#include "../../../basic/geometry/IdbLayerShape.h"
#include "../db_layout/IdbLayer.h"

namespace idb {

using std::map;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class IdbObsLayer
{
 public:
  IdbObsLayer();
  ~IdbObsLayer();

  // getter
  IdbLayerShape* get_shape() { return _layer_shape; }

  // setter
  void set_shape(IdbLayerShape* layer_shape) { _layer_shape = layer_shape; }

  // operator

 private:
  IdbLayerShape* _layer_shape;
};

class IdbObs
{
 public:
  IdbObs();
  ~IdbObs();

  // getter
  uint32_t get_obs_layer_num() { return _obs_layer_list.size(); }
  std::vector<IdbObsLayer*>& get_obs_layer_list() { return _obs_layer_list; }

  // setter
  IdbObsLayer* add_obs_layer(IdbObsLayer* obs_layer = nullptr);

  // operator

 private:
  std::vector<IdbObsLayer*> _obs_layer_list;
};

}  // namespace idb
