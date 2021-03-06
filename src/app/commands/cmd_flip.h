// Aseprite
// Copyright (C) 2001-2015  David Capello
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.

#ifndef APP_COMMANDS_CMD_FLIP_H_INCLUDED
#define APP_COMMANDS_CMD_FLIP_H_INCLUDED
#pragma once

#include "app/commands/command.h"
#include "doc/algorithm/flip_type.h"

namespace app {

  class FlipCommand : public Command {
  public:
    FlipCommand();
    Command* clone() const override { return new FlipCommand(*this); }

    doc::algorithm::FlipType getFlipType() const { return m_flipType; }

  protected:
    void onLoadParams(Params* params);
    bool onEnabled(Context* context);
    void onExecute(Context* context);
    std::string onGetFriendlyName() const;

  private:
    bool m_flipMask;
    doc::algorithm::FlipType m_flipType;
  };

} // namespace app

#endif // APP_COMMANDS_CMD_FLIP_H_INCLUDED
