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

#include <map>
#include <set>
#include <string>
#include <vector>

#include "MPDB.hh"
#include "Setting.hh"
#include "SimulateAnneal.hh"
#include "config/Config.hh"
#include "module/logger/Log.hh"
#include "partition/HierPartition.hh"
#include "partition/MPPartition.hh"
#include "simulate_anneal/MPEvaluation.hh"
#include "simulate_anneal/SolutionFactory.hh"

using std::string;
using std::vector;

namespace ipl::imp {

class MacroPlacer
{
 public:
  MacroPlacer(MPDB* mdb, ipl::Config* config) : _mdb(mdb)
  {
    _mp_config = config->get_mp_config();
    init();
  }
  ~MacroPlacer() = default;
  // open functions
  void runMacroPlacer();

  void darwPartition();
  map<FPInst*, int> partitionInst(int part);

 private:
  void init();
  void updateDensity();
  void setFixedMacro();
  void addHalo();
  void addBlockage();
  void addGuidance();
  void writeSummary(double time);
  void initLocation();
  // data
  MPDB* _mdb;
  Setting* _set;
  MacroPlacerConfig _mp_config;
};

}  // namespace ipl::imp