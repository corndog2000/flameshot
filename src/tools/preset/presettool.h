// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors
// Joseph Schroedl | April 18th, 2021 | github.com/corndog2000

#pragma once

#include "src/tools/abstractactiontool.h"

class PresetTool : public AbstractActionTool
{
    Q_OBJECT
public:
    explicit PresetTool(QObject* parent = nullptr);

    bool closeOnButtonPressed() const override;

    QIcon icon(const QColor& background, bool inEditor) const override;
    QString name() const override;
    QString description() const override;

    CaptureTool* copy(QObject* parent = nullptr) override;

protected:
    ToolType nameID() const override;

public slots:
    void pressed(const CaptureContext& context) override;

signals:
    void sendPreset(QRect rect);
};
