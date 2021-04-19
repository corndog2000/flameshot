// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors
// Joseph Schroedl | April 18th, 2021 | github.com/corndog2000

#include "presettool.h"
#include <QPainter>

PresetTool::PresetTool(QObject* parent)
  : AbstractActionTool(parent)
{}

bool PresetTool::closeOnButtonPressed() const
{
    return false;
}

QIcon PresetTool::icon(const QColor& background, bool inEditor) const
{
    //return QIcon(iconPath(background) + "content-copy.svg");
    return inEditor ? QIcon()
                    : QIcon(iconPath(background) + "size_indicator.svg");
}
QString PresetTool::name() const
{
    return tr("Preset");
}

ToolType PresetTool::nameID() const
{
    return ToolType::PRESET;
}

QString PresetTool::description() const
{
    return tr("Resize selection to preset");
}

CaptureTool* PresetTool::copy(QObject* parent)
{
    return new PresetTool(parent);
}

void PresetTool::pressed(const CaptureContext& context)
{
    // This is where the magic happens and we resize the window to the preset size
    //context.cw->repositionSelection(QRect(200, 200, 200, 200));
    
    // Tell the capture widget to resize the selection
    emit sendPreset(QRect(200, 200, 200, 200));
}
