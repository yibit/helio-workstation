/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "MidiEventComponent.h"

class MidiEventComponentLasso : public Component
{
public:

    MidiEventComponentLasso();

    enum ColourIds
    {
        lassoFillColourId       = 0x1000440,
        lassoOutlineColourId    = 0x1000441,
    };


    virtual void beginLasso(const MouseEvent &e,
                            LassoSource<MidiEventComponent *> *const lassoSource);

    virtual void dragLasso(const MouseEvent &e);

    virtual void endLasso();
    
    virtual bool isDragging() const;

    void paint(Graphics &g) override;

    bool hitTest(int, int) override { return false; }

private:

    Array<MidiEventComponent *> originalSelection;

    LassoSource<MidiEventComponent *> *source;

    Point<int> dragStartPos;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiEventComponentLasso)
};
