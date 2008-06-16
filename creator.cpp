/*
  Copyright (c) 2008 Riccardo Iaconelli <riccardo@kde.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
*/

#include "creator.h"
#include <QGraphicsGridLayout>
#include <KLocalizedString>
#include <Plasma/Label>
#include <Plasma/LineEdit>
#include <Plasma/PushButton>

Creator::Creator(QGraphicsItem *parent = 0)
    : QGraphicsWidget(0)
{
    m_toLabel = new Plasma::Label(this);
    m_messageLabel = new Plasma::Label(this);
    m_to = new Plasma::LineEdit(this);
    m_message = new Plasma::LineEdit(this);
    m_addButton = new Plasma::PushButton(this);
    m_layout = new QGraphicsGridLayout(this);

    m_toLabel->setText(i18n("Tell to:"));
    m_messageLabel->setText(i18n("Message:"));
    m_addButton->setText(i18n("Add!"));

    m_layout->addItem(m_toLabel, 0, 0);
    m_layout->addItem(m_to, 1, 0);
    m_layout->addItem(m_messageLabel, 0, 1);
    m_layout->addItem(m_message, 1, 1);
    m_layout->addItem(m_addButton, 0, 2, 2, 1);

    connect(m_addButton, SIGNAL(clicked()), this, SLOT(slotAdd()));

    setLayout(m_layout);
}

void Creator::slotAdd()
{
    emit add(m_to->text(), m_message->text());
}

#include "creator.moc"
