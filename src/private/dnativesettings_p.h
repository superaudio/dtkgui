/*
 * Copyright (C) 2017 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     zccrs <zccrs@live.com>
 *
 * Maintainer: zccrs <zhangjide@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DNATIVESETTINGS_P_H
#define DNATIVESETTINGS_P_H

#include <dobject_p.h>
#include <dtkgui_global.h>
#include <dnativesettings.h>

DGUI_BEGIN_NAMESPACE

class DNativeSettingsPrivate : public QObject, public DCORE_NAMESPACE::DObjectPrivate
{
    D_DECLARE_PUBLIC(DNativeSettings)
public:
    DNativeSettingsPrivate(DNativeSettings *qq, const QByteArray &domain);
    ~DNativeSettingsPrivate();

    bool init(const QMetaObject *init, quint32 window);

    const QMetaObject *metaObject() const override;

Q_SIGNALS:
    void propertyChanged(const QByteArray &name, const QVariant &value);

private:
    bool event(QEvent *event) override;

public:
    QByteArray domain;
    QMetaObject *fakeMetaObject = nullptr;
    bool valid = false;
};

DGUI_END_NAMESPACE

#endif // DNATIVESETTINGS_P_H
