//
// Created by minau on 12/1/2022.
//

#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H
#include "stateEnum.h"
#include <map>

class States {
    private:
        std::map<stateEnum, bool>map;
        void load();
    public:
        States();
        bool checkState(stateEnum state) const;
        void enableState(stateEnum state);
        void disableStates(stateEnum state);
        void setState(stateEnum state, bool value);
        void toggleState(stateEnum states);

};


#endif //SFML_PROJECT_STATES_H
