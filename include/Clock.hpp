//
//  Clock.hpp
//  randomgl
//
//  Created by Jean Gravier on 14/08/2014.
//  Copyright (c) 2014 Jean Gravier. All rights reserved.
//

#ifndef randomgl_Clock_hpp
# define randomgl_Clock_hpp

class Clock
{
public:
    Clock();
    virtual ~Clock();
    
    void			reset();
    void			update();
    
    unsigned int	getElapsed() const;
    
private:
    unsigned int	_ticks;
};

#endif
