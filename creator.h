/*
  Copyright (c) 2008 Riccardo Iaconelli <riccardo@kde.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
*/

#ifndef CREATOR_H
#define CREATOR_H

#include <QGraphicsWidget>

class QGraphicsGridLayout;

namespace Plasma {
    class Label;
    class LineEdit;
    class PushButton;
}

class Creator : public QGraphicsWidget
{
    public:
        Creator(QGraphicsItem *parent);

    signals:
        void add(const QString &, const QString &);

    private:
        Plasma::Label *m_toLabel;
        Plasma::Label *m_messageLabel;
        Plasma::LineEdit *m_to;
        Plasma::LineEdit *m_message;
        Plasma::PushButton *m_addButton;
        QGraphicsGridLayout *m_layout;
};

#endif
