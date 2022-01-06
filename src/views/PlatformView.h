//
// Created by Cédric Leclercq on 04/01/2022.
//

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMVIEW_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMVIEW_H

#include "View.h"
#include "../observers/Observers.h"
#include "../observers/entityObservers/PlatformObserver.h"
#include "models/entities/Platform.h"

class Views::PlatformView: public View {
private:
    // Kind of platform
    PKind platformKind{};
    BonusPower bonusKind{};
    bool texLoaded = false;
public:
    std::shared_ptr<Observers::PlatformObserver> observer;
    PlatformView()=default;
    explicit PlatformView(const std::shared_ptr<Entities::Platform>& platform);
    void setup() override;
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_PLATFORMVIEW_H
