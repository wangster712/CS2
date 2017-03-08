/**
 * @file CoordinateStack.cpp
 * @author Ellen Price <<eprice@caltech.edu>>
 * @version 2.0
 * @date 2014-2015
 * @copyright see License section
 *
 * @brief Functions for stack class that stores Coordinate objects.
 *
 * @section License
 * Copyright (c) 2014-2015 California Institute of Technology.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of the  nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the California Institute of Technology.
 *
 */

#include "CoordinateStack.hpp"

#define ANIMATION_DELAY     (25)

/**
 * @brief Initializes the stack.
 *
 * @param[in] app Reference to the MazeSolverApp; needed
 * to render moves.
 */
#ifndef TESTSUITE
CoordinateStack::CoordinateStack(class MazeSolverApp *app)
{
    this->app = app;
    init();
}
#else
CoordinateStack::CoordinateStack()
{
    init();
}
#endif

/**
 * @brief Initializes the stack (student-implemented).
 */
void CoordinateStack::init()
{
    /* TODO: Write your initialization here! */
    top = NULL;
}

/**
 * @brief Deinitializes the stack.
 */
CoordinateStack::~CoordinateStack()
{
    deinit();
}

/**
 * @brief Deinitializes the stack (student-implemented).
 */
void CoordinateStack::deinit()
{
    while (top != NULL){
        stackitem *temp = top;
        top = top -> next;
        delete temp;
        
    }
}

/**
 * @brief Pushes an item onto the stack.
 *
 * @param[in] c Coordinate to push onto the stack.
 */
void CoordinateStack::push(Coordinate c)
{
    /* Do the operation. */
    do_push(c);

#ifndef TESTSUITE
    /* Update the display. */
    SDL_Delay(ANIMATION_DELAY);
    this->app->OnRender();
#endif
}

/**
 * @brief Do the actual push operation (student-implemented).
 *
 * @param[in] c Coordinate to push onto the stack.
 */
void CoordinateStack::do_push(Coordinate c)
{
    /* TODO: Write your push function here! */
    stackitem *temp = new stackitem;
    if (top == NULL)
    {
        temp -> c = c;
        temp-> next = NULL;
        top = temp;        
    }
    else
    {

        temp -> c = c;
        temp-> next = top;
        top = temp;
    }

    
}
/**
 * @brief Pops an item off the stack.
 *
 * @return The popped Coordinate.
 */
Coordinate CoordinateStack::pop()
{
    /* Do the operation. */
    Coordinate c = do_pop();

#ifndef TESTSUITE
    /* Update the display. */
    SDL_Delay(ANIMATION_DELAY);
    this->app->OnRender();
#endif

    return c;
}

/**
 * @brief Do the actual pop operation (student-implemented).
 *
 * @return The popped Coordinate.
 */
Coordinate CoordinateStack::do_pop()
{
    /* TODO: Write your pop function here! */
    
    stackitem *temp = new stackitem;
    if (top == NULL){
        return Coordinate(-999,-999);  //Signifies that stack is empty and nothing to pop
    }
    else
    {
        Coordinate cord = top -> c;
        top = top -> next;
        return cord;        
    }

    

}

/**
 * @brief Returns the top item of the stack without removing it.
 *
 * @return The Coordinate at the top of the stack.
 */
Coordinate CoordinateStack::peek()
{
    /* TODO: Write your peek function here! */
    if (top != NULL){
        return top -> c;
    }
    else{
        return Coordinate(-999,-999);    //Signifies that there is nothing on top of the stack
    }
}

/**
 * @brief Returns true if stack is empty, false otherwise.
 *
 * @return Boolean indicating whether the stack is empty.
 */
bool CoordinateStack::is_empty()
{
    /* TODO: Is the stack empty??? */
    return (top == NULL);
}

/**
 * @brief Helper function for depth search that returns all items on stack
 *
 * @return Vector of coordinates of all stackitems on stack
 */

vector<Coordinate> CoordinateStack::returnCoords()
{
    std::vector<Coordinate> list1;
    stackitem *temp = top;
    while (temp != NULL){
        list1.push_back(temp->c);
        temp = temp -> next;        
    }

    return list1;

}


