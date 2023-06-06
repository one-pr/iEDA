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

#include "Config.hpp"
#include "Database.hpp"
#include "Net.hpp"
#include "VRDataManager.hpp"
#include "VRModel.hpp"

namespace irt {

#define VR_INST (irt::ViolationRepairer::getInst())

class ViolationRepairer
{
 public:
  static void initInst(Config& config, Database& database);
  static ViolationRepairer& getInst();
  static void destroyInst();
  // function
  void repair(std::vector<Net>& net_list);

 private:
  // self
  static ViolationRepairer* _vr_instance;
  // config & database
  VRDataManager _vr_data_manager;

  ViolationRepairer(Config& config, Database& database) { init(config, database); }
  ViolationRepairer(const ViolationRepairer& other) = delete;
  ViolationRepairer(ViolationRepairer&& other) = delete;
  ~ViolationRepairer() = default;
  ViolationRepairer& operator=(const ViolationRepairer& other) = delete;
  ViolationRepairer& operator=(ViolationRepairer&& other) = delete;
  // function
  void init(Config& config, Database& database);
  void repairVRNetList(std::vector<VRNet>& vr_net_list);

#if 1  // build vr_model
  VRModel initVRModel(std::vector<VRNet>& vr_net_list);
  void buildVRModel(VRModel& vr_model);
  void updateNetBlockageMap(VRModel& vr_model);
#endif

#if 1  // check ra_model
  void checkVRModel(VRModel& vr_model);
#endif

#if 1  // repair ra_model
  void repairVRModel(VRModel& vr_model);
  void repairVRNet(VRModel& vr_model, VRNet& vr_net);
  void buildKeyCoordPinMap(VRNet& vr_net);
  void buildCoordTree(VRNet& vr_net);
  void buildPHYNodeResult(VRNet& vr_net);
  void updateConnectionList(TNode<LayerCoord>* coord_node, VRNet& vr_net, std::vector<TNode<PHYNode>*>& pre_connection_list,
                            std::vector<TNode<PHYNode>*>& post_connection_list);
  TNode<PHYNode>* makeWirePHYNode(VRNet& vr_net, LayerCoord first_coord, LayerCoord second_coord);
  TNode<PHYNode>* makeViaPHYNode(VRNet& vr_net, irt_int below_layer_idx, PlanarCoord coord);
  TNode<PHYNode>* makePinPHYNode(VRNet& vr_net, irt_int pin_idx, LayerCoord coord);
  void repairMinArea(VRNet& vr_net);
  void updateNetBlockageMap(VRModel& vr_model, VRNet& vr_net);
  std::vector<LayerRect> getRealRectList(MTree<PHYNode>& phy_node_tree);
#endif

#if 1  // update ra_model
  void updateVRModel(VRModel& vr_model);
  void updateOriginVRResultTree(VRModel& vr_model);
#endif

#if 1  // report ra_model
  void reportVRModel(VRModel& vr_model);
  void countVRModel(VRModel& vr_model);
  void reportTable(VRModel& vr_model);
#endif
};

}  // namespace irt
