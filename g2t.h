/*
  Copyright (c) 2008 Riccardo Iaconelli <riccardo@kde.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
*/

 // Here we avoid loading the header multiple times
#ifndef G2T_HEADER
#define G2T_HEADER
// We need the Plasma Applet headers
#include <KIcon>
 
#include <Plasma/Applet>
#include <Plasma/Svg>
 
class QSizeF;
 
// Define our plasma Applet
class G2t : public Plasma::Applet
{
    Q_OBJECT
    public:
        // Basic Create/Destroy
        G2t(QObject *parent, const QVariantList &args);
        ~G2t();
 
        // The paintInterface procedure paints the applet to screen
        void paintInterface(QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                const QRect& contentsRect);
        void init();
 
    private:
        Plasma::Svg m_svg;
        KIcon m_icon;
};
 
// This is the command that links your applet to the .desktop file
K_EXPORT_PLASMA_APPLET(g2t, G2t)
#endif

