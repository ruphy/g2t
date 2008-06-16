/*
  Copyright (c) 2008 Riccardo Iaconelli <riccardo@kde.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
*/


#include "g2t.h"
#include "reminder.h"
#include "creator.h"
#include <QPainter>
#include <QFontMetrics>
#include <QSizeF>
#include <QGraphicsLinearLayout>

#include <Plasma/Svg>
#include <Plasma/Theme>
#include <Plasma/PushButton>

G2t::G2t(QObject *parent, const QVariantList &args)
    : Plasma::Applet(parent, args),
    m_svg(this),
    m_icon("plasma")
{
    // this will get us the standard applet background, for free!
    setBackgroundHints(Plasma::Applet::StandardBackground);
    resize(200, 200);
    m_layout = new QGraphicsLinearLayout(Qt::Vertical, this);
    m_newReminderButton = new Plasma::PushButton(this);
    m_layout->addItem(m_newReminderButton);
    resize(m_layout->sizeHint(Qt::PreferredSize));

    connect(m_newReminderButton, SIGNAL(clicked()), this, SLOT(addReminder()));

    setLayout(m_layout);
}

G2t::~G2t()
{
    if (hasFailedToLaunch()) {
        // Do some cleanup here
    } else {
        // Save settings
    }
}

void G2t::init()
{
    //TODO: read the storage file and load all reminders

    // A small demonstration of the setFailedToLaunch function
    if (m_icon.isNull()) {
        setFailedToLaunch(true, "No world to say hello");
    }
}

void G2t::addReminder()
{
    m_creator = new Creator(this);
    m_layout->addItem(m_creator); // TODO make me slide in
    resize(m_layout->sizeHint(Qt::PreferredSize));
    connect(m_creator, SIGNAL(add(const QString &, const QString &)), this, SLOT(reminderAdded(const QString &, const QString &)));
}

void G2t::reminderAdded(const QString &to, const QString &message)
{
    disconnect(m_creator, SIGNAL(add(const QString &, const QString &)), this, SLOT(reminderAdded(const QString &, const QString &)));
    m_layout->removeItem(m_creator); // TODO make me slide out
    resize(m_layout->sizeHint(Qt::PreferredSize));
    m_creator->deleteLater();

    // TODO store the message =)
}

void G2t::paintInterface(QPainter *p,
        const QStyleOptionGraphicsItem *option, const QRect &contentsRect)
{
    p->setRenderHint(QPainter::SmoothPixmapTransform);
    p->setRenderHint(QPainter::Antialiasing);

    p->setClipRect(boundingRect());

    // Now we draw the applet, starting with our svg
    m_svg.resize((int)contentsRect.width(), (int)contentsRect.height());
    m_svg.paint(p, (int)contentsRect.left(), (int)contentsRect.top());

    // We place the icon and text
    p->drawPixmap(7, 0, m_icon.pixmap((int)contentsRect.width(),(int)contentsRect.width()-14));
    p->save();
    p->setPen(Qt::white);
    p->drawText(contentsRect,
                Qt::AlignBottom | Qt::AlignHCenter,
                "Hello Plasmoid!");
    p->restore();
}

#include "g2t.moc"

