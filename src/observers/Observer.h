// // // // // // // // // // // // // //
//                                     //
//             Observer.h              //
//          Cédric Leclercq            //
//                                     //
// // // // // // // // // // // // // //

#ifndef ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVER_H
#define ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVER_H

#include <utility>

#include "utilities/Utilities.h"
using Coordinates = Utilities::Coordinates;

/**
 * @class Observer
 * @brief Super class for all the observers
 */
class Observer {
protected:
    /// @brief Parameter for if the observer has been notified
    bool notified{};
public:
    /**
     * @brief Simple default constructor
     */
    Observer()=default;
    /**
     * @brief Default destructor
     */
    virtual ~Observer()=default;
    /**
     * @brief Will notify the observer and set the notified parameter to true
     */
    virtual void notifyObserver() {notified = true;}
    /**
     * @brief Getter for if the observer is notified
     * @return      isNotified?
     */
    virtual bool getNotified() {return notified;}
};


#endif //ADVANCEDPROGRAMMINGDOODLEJUMP_OBSERVER_H
