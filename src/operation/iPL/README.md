# iPL用户指南

> ## iPL简介

### 软件结构图

<div align="center">

<img src="../../../docs/resources/iPL.png" width="60%" height="35%" alt="iPL-logo" />

  **iPL--一款面向流片需求，支持合法摆放M1层单元的自动布局器**

</div>

### 支持功能

- 支持标准单元的全局布局、合法化、详细布局；
- 支持对布局结果进行违例检查、报告布局阶段线长、密度、时序、拥塞
- 支持在布局阶段插入buffer进行长线优化；
- 支持增量式合法化；
- 时序优化与拥塞优化进一步完善中；

---

> ## iPL使用示例

### 通过tcl启动

参考iPL_script/run_iPL.tcl： `<ieda_path>/scripts/sky130/script/iPL_script/run_iPL.tcl`

iPL支持使用的tcl命令

```
run_placer -conifg <config_path> // 完整运行整个iPL
run_filler -conifg <config_path> // 对布局的空白区域进行单元填充
run_incremental_flow -conifg <config_path> // 对改变单元位置的结果进行重新合法化
run_incremental_lg // 进行增量式合法化，需保证iPL已运行
placer_check_legality // 检查当前布局的合法性
placer_report // 对当前布局的状态进行report
init_pl -conifg <config_path> // 对布局器进行初始化
destroy_pl // 销毁布局器
placer_run_mp // 进行宏单元布局
placer_run_gp // 进行标准单元全局布局
placer_run_lg // 进行标准单元合法化
placer_run_dp // 进行标准单元详细布局
```

### Config配置文件

参考iEDA_config/pl_default_config.json: `<ieda_path>/scripts/sky130/iEDA_config/pl_default_config.json`

| JSON参数                                      | 功能说明                                                                                                                    | 参数范围                     | 默认值        |
| --------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- | ---------------------------- | ------------- |
| is_max_length_opt                             | 是否开启最大线长优化                                                                                                        | [0,1]                        | 0             |
| max_length_constraint                         | 指定最大线长                                                                                                                | [0-1000000]                  | 1000000       |
| is_timing_aware_mode                          | 是否开启时序模式                                                                                                            | [0,1]                        | 0             |
| ignore_net_degree                             | 忽略超过指定pin个数的线网                                                                                                   | [10-10000]                   | 100           |
| num_threads                                   | 指定的CPU线程数                                                                                                             | [1-64]                       | 8             |
| [GP-Wirelength] init_wirelength_coef          | 设置初始线长系数                                                                                                            | [0.0-1.0]                    | 0.25          |
| [GP-Wirelength] reference_hpwl                | 调整密度惩罚的参考线长                                                                                                      | [100-1000000]                | 446000000     |
| [GP-Wirelength] min_wirelength_force_bar      | 控制线长边界                                                                                                                | [-1000-0]                    | -300          |
| [GP-Density] target_density                   | 指定的目标密度                                                                                                              | [0.0-1.0]                    | 0.8           |
| [GP-Density] bin_cnt_x                        | 指定水平方向上Bin的个数                                                                                                     | [16,32,64,128,256,512,1024]  | 512           |
| [GP-Density] bin_cnt_y                        | 指定垂直方向上Bin的个数                                                                                                     | [16,32,64,128,256,512,1024]  | 512           |
| [GP-Nesterov] max_iter                        | 指定最大的迭代次数                                                                                                          | [50-2000]                    | 2000          |
| [GP-Nesterov] max_backtrack                   | 指定最大的回溯次数                                                                                                          | [0-100]                      | 10            |
| [GP-Nesterov] init_density_penalty            | 指定初始状态的密度惩罚                                                                                                      | [0.0-1.0]                    | 0.00008       |
| [GP-Nesterov] target_overflow                 | 指定目标的溢出值                                                                                                            | [0.0-1.0]                    | 0.1           |
| [GP-Nesterov] initial_prev_coordi_update_coef | 初始扰动坐标时的系数                                                                                                        | [10-10000]                   | 100           |
| [GP-Nesterov] min_precondition                | 设置precondition的最小值                                                                                                    | [1-100]                      | 1             |
| [GP-Nesterov] min_phi_coef                    | 设置最小的phi参数                                                                                                           | [0.0-1.0]                    | 0.95          |
| [GP-Nesterov] max_phi_coef                    | 设置最大的phi参数                                                                                                           | [0.0-1.0]                    | 1.05          |
| [BUFFER] max_buffer_num                       | 指定限制最大buffer插入个数                                                                                                  | [0-1000000]                  | 35000         |
| [BUFFER] buffer_type                          | 指定可插入的buffer类型名字                                                                                                  | 工艺相关                     | 列表[...,...] |
| [LG] max_displacement                         | 指定单元的最大移动量                                                                                                        | [10000-1000000]              | 50000         |
| [LG] global_right_padding                     | 指定单元间的间距（以Site为单位）                                                                                            | [0,1,2,3,4...]               | 1             |
| [DP] max_displacement                         | 指定单元的最大移动量                                                                                                        | [10000-1000000]              | 50000         |
| [DP] global_right_padding                     | 指定单元间的间距（以Site为单位）                                                                                            | [0,1,2,3,4...]               | 1             |
| [Filler] first_iter                           | 指定第一轮迭代使用的Filler                                                                                                  | 工艺相关                     | 列表[...,...] |
| [Filler] second_iter                          | 指定第二轮迭代使用的Filler                                                                                                  | 工艺相关                     | 列表[...,...] |
| [Filler] min_filler_width                     | 指定Filler的最小宽度（以Site为单位）                                                                                        | 工艺相关                     | 1             |
| [MP] fixed_macro                              | 指定固定的宏单元 (string macro_name)                                                                                        | 设计相关                     | 列表[...,...] |
| [MP] fixed_macro_coordinate                   | 指定固定宏单元的位置坐标（int location_x, int location_y）                                                                  | 设计相关                     | 列表[...,...] |
| [MP] blockage                                 | 指定宏单元阻塞矩形区域，宏单元应该避免摆放在该区域（int left_bottom_x, int left_bottom_y, int right_top_x, int right_top_y) | 设计相关                     | 列表[...,...] |
| [MP] guidance_macro                           | 指定指导摆放宏单元，每个宏单元可以设置期望摆放的区域 (string macro_name)                                                    | 设计相关                     | 列表[...,...] |
| [MP] guidance                                 | 指定对应宏单元的指导摆放区域（int left_bottom_x, int left_bottom_y, int right_top_x, int right_top_y）                      | 设计相关                     | 列表[...,...] |
| [MP] solution_type                            | 指定解的表示方式                                                                                                            | ["BStarTree","SequencePair"] | "BStarTree"   |
| [MP] perturb_per_step                         | 指定模拟退火每步扰动次数                                                                                                    | [10-1000]                    | 100           |
| [MP] cool_rate                                | 指定模拟退火温度冷却率                                                                                                      | [0.0-1.0]                    | 0.92          |
| [MP] parts                                    | 指定标准单元划分数（int)                                                                                                    | [10-100]                     | 66            |
| [MP] ufactor                                  | 指定标准单元划分不平衡值 (int)                                                                                              | [10-1000]                    | 100           |
| [MP] new_macro_density                        | 指定虚拟宏单元密度                                                                                                          | [0.0-1.0]                    | 0.6           |
| [MP] halo_x                                   | 指定宏单元的halo（横向）                                                                                                    | [0-1000000]                  | 0             |
| [MP] halo_y                                   | 指定宏单元的halo（纵向）                                                                                                    | [0-1000000]                  | 0             |
| [MP] output_path                              | 指定输出文件路径                                                                                                            |                              | "./result/pl" |

### 运行的Log、Report

默认存放在目录：`<ieda_path>/scripts/sky130/result/pl/`

* report/violation_record.txt ：布局违例的单元
* report/wirelength_record.txt ：布局的HPWL线长、STWL线长以及长线线长统计
* report/density_record.txt ：布局的峰值bin密度
* report/timing_record.txt ：布局的时序信息（wns、tns），调用Flute进行简易绕线
