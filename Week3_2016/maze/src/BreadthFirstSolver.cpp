/**
 * @file BreadthFirstSolver.cpp
 * @author Ellen Price <<eprice@caltech.edu>>
 * @version 2.0
 * @date 2014-2015
 * @copyright see License section
 *
 * @brief Functions for maze solver that implements breadth-first search.
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

#include "BreadthFirstSolver.hpp"

/**
 * @brief Initializes the solver.{
    
 }
 *
 * @param[in] app Pointer to the main MazeSolverApp class.
 */
BreadthFirstSolver::BreadthFirstSolver(class MazeSolverApp *app)
{
    queue = new CoordinateQueue(app);
    init();
}

/**
 * @brief Initializes the solver (student-implemented).
 */
void BreadthFirstSolver::init()
{
    for (int i = 0 ; i < WIDTH; i++){
        for (int j = 0 ; j < HEIGHT; j++){
            visited[i][j].visited = false;
            visited[i][j].from = Coordinate(-999,-999);
        }
    }


}

/**
 * @brief Deinitializes the solver.
 */
BreadthFirstSolver::~BreadthFirstSolver()
{
    delete queue;
    deinit();
}

/**
 * @brief Deinitializes the solver (student-implemented).
 */
void BreadthFirstSolver::deinit()
{
    
}

/**
 * @brief Solve the maze given by `maze`.
 *
 * @param[in] maze MazeGrid object that stores the maze to be
 * solved.
 */
void BreadthFirstSolver::solve(MazeGrid *maze)
{
    Coordinate currentCoord;
    queue->enqueue(Coordinate(MAZE_START_X, MAZE_START_Y));

    while (!queue->is_empty())
    {
        currentCoord = queue->peek();
        visited[currentCoord.x][currentCoord.y].visited = true;

        if (currentCoord.x == MAZE_END_X && currentCoord.y == MAZE_END_Y){
            break;
        }

        else
        {
            int res = maze->get_possible_moves(currentCoord.x,currentCoord.y);


            if ((res & E) && (visited[currentCoord.x+1][currentCoord.y].visited == false))
            {
                queue->enqueue(Coordinate(currentCoord.x+1, currentCoord.y));
                visited[currentCoord.x+1] [currentCoord.y].from = currentCoord;

            }

            if ((res & W) && (visited[currentCoord.x-1][currentCoord.y].visited == false))
            {
                queue->enqueue(Coordinate(currentCoord.x-1, currentCoord.y));
                visited[currentCoord.x-1][currentCoord.y].from = currentCoord;

                
            }

            if ((res & N) && (visited[currentCoord.x][currentCoord.y-1].visited == false))
            {
                queue->enqueue(Coordinate(currentCoord.x, currentCoord.y-1));
                visited[currentCoord.x][currentCoord.y-1].from = currentCoord;


            }

            if ((res & S) && (visited[currentCoord.x][currentCoord.y+1].visited == false))
            {
                queue->enqueue(Coordinate(currentCoord.x, currentCoord.y+1));
                visited[currentCoord.x] [currentCoord.y+1].from = currentCoord;

            
            }

            queue->dequeue();
            
        }

    }
    /* TODO: Solve the maze.
     *
     * You are provided a member variable `visited` that stores
     * (bool, Coordinate) pairs describing whether a square has already
     * been checked and the square immediately preceding it in the path.
     * You are responsible for maintaining this array, filling it with
     * useful information, and using it in a consistent way. */
}

/**
 * @brief Retrieves the current path through the maze.
 *
 * @return Vector storing the current path through the maze.
 */
vector<Coordinate> BreadthFirstSolver::get_path()
{
    vector<Coordinate> list;

    Coordinate c = queue->peek();

    while (c.x != -999 && c.y != -999){
        list.push_back(c);
        c = visited[c.x][c.y].from;
    }

    /* TODO: Find the current path through the maze and return it as a vector.
     * For a BFS, this is a little tricky -- the top element in the queue
     * only tells you the last point in the path; you need to trace back up
     * using the `visited` member array. */

    return list;
}

