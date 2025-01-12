/**
 * @file CmdDefToVerilog.cc
 * @author simin tao (taosm@pcl.ac.cn)
 * @brief The implemention of def to verilog command.
 * @version 0.1
 * @date 2023-06-12
 */
#include "ShellCmd.hh"
#include "builder.h"

namespace ista {

CmdDefToVerilog::CmdDefToVerilog(const char* cmd_name) : TclCmd(cmd_name) {
  auto* def_option = new TclStringOption("-def", 0, nullptr);
  addOption(def_option);

  auto* lef_option = new TclStringListOption("-lef", 0);
  addOption(lef_option);

  auto* verilog_option = new TclStringOption("-verilog", 0, nullptr);
  addOption(verilog_option);
}

unsigned CmdDefToVerilog::check() { return 1; }

unsigned CmdDefToVerilog::exec() {
  if (!check()) {
    return 0;
  }

  auto* db_builder = new idb::IdbBuilder();

  TclOption* lef_option = getOptionOrArg("-lef");
  auto lef_files = lef_option->getStringList();

  db_builder->buildLef(lef_files);

  TclOption* def_option = getOptionOrArg("-def");
  auto* def_file = def_option->getStringVal();
  db_builder->buildDef(def_file);

  TclOption* verilog_option = getOptionOrArg("-verilog");
  auto* verilog_file = verilog_option->getStringVal();

  std::set<std::string> exclude_cell_names;
  db_builder->saveVerilog(verilog_file, exclude_cell_names);

  return 1;
}

}  // namespace ista
