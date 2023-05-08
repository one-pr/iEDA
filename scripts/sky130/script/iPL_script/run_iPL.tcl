#===========================================================
##   init flow config
#===========================================================
flow_init -config ./iEDA_config/flow_config.json

#===========================================================
##   read db config
#===========================================================
db_init -config ./iEDA_config/db_default_config.json

#===========================================================
##   reset data path
#===========================================================
source ./script/DB_script/db_path_setting.tcl

#===========================================================
##   reset lib
#===========================================================
source ./script/DB_script/db_init_lib.tcl

#===========================================================
##   reset sdc
#===========================================================
source ./script/DB_script/db_init_sdc.tcl

#===========================================================
##   read lef
#===========================================================
source ./script/DB_script/db_init_lef.tcl

#===========================================================
##   read def
#===========================================================
def_init -path ./result/iTO_fix_fanout_result.def

#===========================================================
##   run Placer
#===========================================================
run_placer -config ./iEDA_config/pl_default_config.json

#===========================================================
##   Save def 
#===========================================================
def_save -path ./result/iPL_result.def

#===========================================================
##   Save netlist 
#===========================================================
netlist_save -path ./result/iPL_result.v -exclude_cell_names {}

#===========================================================
##   report 
#===========================================================
report_db -path "./result/report/pl_db.rpt"

#===========================================================
##   Exit 
#===========================================================
flow_exit
