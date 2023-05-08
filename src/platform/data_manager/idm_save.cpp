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
 * @File Name: dm_save.cpp
 * @Brief :
 * @Author : Yell (12112088@qq.com)
 * @Version : 1.0
 * @Creat Date : 2022-04-15
 *
 */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "idm.h"

namespace idm {

bool DataManager::save(std::string name, std::string def_path)
{
  std::string full_path = def_path + "/" + name + ".def";
  std::cout << full_path << std::endl;

  if (_idb_builder == nullptr) {
    return false;
  }

  if (def_path.empty()) {
    def_path = _config.get_output_path();
  }

  if (def_path.empty()) {
    return false;
  }

  full_path = def_path + "/" + name + ".def";

  if (!saveDef(full_path)) {
    return false;
  }

  return true;
}

bool DataManager::saveDef(string def_path)
{
  if (_idb_builder == nullptr || _idb_lef_service == nullptr || _layout == nullptr) {
    return false;
  }
  return _idb_builder->saveDef(def_path);
}

void DataManager::saveVerilog(string verilog_path, std::set<std::string>&& exclude_cell_names /*={}*/)
{
  if (_idb_builder == nullptr || _idb_lef_service == nullptr || _layout == nullptr) {
    std::cout << "idb_builder error.\n";
  }
  return _idb_builder->saveVerilog(verilog_path, exclude_cell_names);
}

bool DataManager::saveGDSII(string path)
{
  if (_idb_builder == nullptr || _idb_lef_service == nullptr || _layout == nullptr) {
    return false;
  }
  return _idb_builder->saveGDSII(path);
}

}  // namespace idm
