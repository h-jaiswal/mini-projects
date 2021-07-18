#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Global r and c values for running instance of the game
const int r = 3, c = 4;

// TO DO - SHIFT TO VECTOR or DYNAMIC ARRAYS.

bool initialize_game()
{

    cout << "Enter R and C (space seperated input): ";
    //cin >> r >> c;

    if ( (2 <= r && r <= 20) &&  (2 <= c && c <= 20) )
    {
        cout << "Game initialized for " << r << " x " << c << " matrix.\n";
         return true;
    }
    return false;
} 

struct Line
{
    int dot_1 = -1;
    int dot_2 = -1;
};

class Point
{
public:
    int r_index;
    int c_index;

    Point()
    {

    }

    Point(int dot) // dot is dot number
    {
        this->c_index = (dot % c) - 1; 
        this->r_index = dot / c;

    }

    bool is_not_diagonal_points(Point point_2)
    {
        bool c1, c2, c3, c4;

        // TODO - Simplify using methods and == overloading

        if( 0 <= this->r_index - 1 && this->r_index - 1 < r )
        {
            if( 0 <= this->c_index - 1 && this->c_index - 1 < c )
            {
                c1 = this->r_index - 1 == point_2.r_index && this->c_index -1 == point_2.c_index;
            }
            if( 0 <= this->c_index + 1 && this->c_index + 1 < c )
            {
                c2 = this->r_index - 1 == point_2.r_index && this->c_index + 1== point_2.c_index;
            }
        }

        if( 0 <= this->r_index + 1 && this->r_index + 1 < r )
        {
            if( 0 <= this->c_index - 1 && this->c_index - 1 < c )
            {
                c3 = this->r_index + 1 == point_2.r_index && this->c_index -1 == point_2.c_index;
            }
            if( 0 <= this->c_index + 1 && this->c_index + 1 < c )
            {
                c4 = this->r_index + 1 == point_2.r_index && this->c_index + 1== point_2.c_index;
            }
        }

        if ( c1 || c2 || c3 || c4 )
        {
            return false;
        }

        return true;
    }
    
    bool filled(const  array< array<int, (const int) c > , (const int) r > & game_matrix )
    {
        if ( game_matrix[r_index][c_index] != 0)
            return true;
        return false;
    }

    bool validate()
    {
        // validate r_index and c_index
        if ( ( 0 <= this->r_index && this->r_index <= r ) && ( 0 <= this->c_index && this->c_index <= c ) )
        {
            return true;
        }
        return false;
    }
};
// score is encapsulated inside of a class to allow more restriction to values
class Score
{
    public:
    int score;

    Score()
    {
        score = 0;
    }
    Score(int score)
    {
        if( score > 0)
        {
            this->score = score;
        }
    }

    void increment()
    {
        this->score += 1;
    }

};

bool is_valid_dot(int dot_number)
{
    if ( 1 <= dot_number && dot_number <= r*c )
    {
        return true;
    }
    return false;
}

void update_score(const Point &point, const array< array<int, c> , r > & game_matrix , int current_player, Score &score)
{
  
    Point up, down, left, right;

    Point diagonal;

    up.r_index = point.r_index - 1;
    up.c_index = point.c_index;

    down.r_index = point.r_index + 1;
    down.c_index = point.c_index;

    left.r_index = point.r_index - 1;
    left.c_index = point.c_index;

    right.r_index = point.r_index + 1;
    right.c_index = point.c_index;

    // check for lower right square 
    // down
    // diagonal
    // right
    diagonal.r_index = point.r_index - 1;
    diagonal.c_index = point.c_index + 1;

    if( down.validate() && diagonal.validate() && right.validate() )
    {
        if (down.filled(game_matrix) && diagonal.filled(game_matrix) && right.filled(game_matrix) ) 
        {
            // update current player score
            score.increment();
        }
    }

    // check for upper right square
     // up 
    // diagonal 
    // right
    diagonal.r_index = point.r_index + 1;
    diagonal.c_index = point.c_index + 1;

    if( up.validate() && diagonal.validate() && right.validate() )
    {
        if (up.filled(game_matrix) && diagonal.filled(game_matrix) && right.filled(game_matrix) ) 
        {
            // update current player score
            score.increment();
        }
    }

    // check for lower left square
    // down
    // diagonal
    // left
    diagonal.r_index = point.r_index - 1;
    diagonal.c_index = point.c_index - 1;

    if( down.validate() && diagonal.validate() && left.validate() )
    {
        if (down.filled(game_matrix) && diagonal.filled(game_matrix) && left.filled(game_matrix) ) 
        {
            // update current player score
            score.increment();
        }
    }

    // check for upper left square
    // up 
    // diagonal 
    // left
    diagonal.r_index = point.r_index - 1;
    diagonal.c_index = point.c_index + 1;

    if( up.validate() && diagonal.validate() && left.validate() )
    {
        if (up.filled(game_matrix) && diagonal.filled(game_matrix) && left.filled(game_matrix) ) 
        {
            // update current player score
            score.increment();
        }
    }

    
}

bool connect_dots(const Line &line, array< array<int, c> , r > & game_matrix , int current_player, Score &score)
{
    // line connection as per rules ONLY
    Point point_1(line.dot_1);
    Point point_2(line.dot_2);

    // Now we have the row and column index of both dots to be connected

    // verify these are not diagonal to each other
    // if not, ** TODO ** then connect other wise ask again for playter input

    if ( point_1.is_not_diagonal_points(point_2) ) // return false if diagonal points

    {
        game_matrix[point_1.r_index][point_1.c_index] = current_player;
        game_matrix[point_2.r_index][point_2.c_index] = current_player;

        // update score of current player

        int prev_score = score.score;

        update_score(point_1, game_matrix ,current_player, score);
        update_score(point_2, game_matrix ,current_player, score);

        if ( score.score != prev_score )
        {
            return true; // updated
        } else
        {
            return false; // not updated
        }
    }

}

Line player_input(const int &current_player)
{
    // Ask for input

    int dot_number_1;
    int dot_number_2;

    cout << "Enter input for Player P" << current_player << ": ";
    scanf("%d to %d", &dot_number_1, &dot_number_2); // ex 3 to 6

    // validation of player input
    // allowed connection -> adjacent right, left, top, bottom
    // no invalid dot number allowed

    if( is_valid_dot(dot_number_1) && is_valid_dot(dot_number_2) )
    {
        Line line;
        line.dot_1 = dot_number_1;
        line.dot_2 = dot_number_2;
        return line;
    }
    else
    {
        // the code continually asks the user for valid dot numbers
        cout << "Invalid dot number. Please enter again.\n";
        player_input(current_player);
    }
    Line line;
    return line;
}
void switch_player(int & current_player)
{   
    if (current_player ==0)
    {
        current_player = 1;
    }
    else
    {
        if (current_player == 1)
            current_player = 2;
        else
            current_player = 1;
    }
    
}

bool is_filled_game_matrix( const array< array<int, c> , r > & game_matrix )
{   
    int count = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if ( game_matrix[i][j] != 0 )
            {
                count++;
            }
        }
    }
    if (count == r * c)
    {
        return true;
    }
    return false;
}

void display_game_matrix( array< array<int, c> , r > & game_matrix  )
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << game_matrix[i][j]  << " ";
        }
        cout << endl;
    }
}
void initialize_game_matrix( array< array<int, c> , r > & game_matrix )
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            game_matrix[i][j] = 0;
        }
        
    }
}

void display_result(Score score_1, Score score_2)
{
    cout << "P1 : " << score_1.score << " P2 : " << score_2.score << endl;

}
            
int main()
{
    if( initialize_game() )
    {
        // run game instance

        Score score_1;
        Score score_2;

        array< array<int, c> , r > game_matrix;
        
        // initialize the game_matrix
        initialize_game_matrix(game_matrix);

        int current_player = 0; // 0 means no player, 1 means player 1 and 2 means player 2

        // game starts
        // First ever turn is of player 1

        bool to_switch = true;

        while(true)
        {
                
            if ( to_switch)
            {
                switch_player(current_player);
            }

            Line line = player_input(current_player);
            
            /*
            Cases with connect_dots
            1. Bonus turn
            2. Next player turn

            */
            {
                
                switch (current_player)
                {
                    case 1:  to_switch = ! connect_dots(line, game_matrix, current_player, score_1);
                    break;
                    case 2:  to_switch = ! connect_dots(line, game_matrix, current_player, score_2);
                    break;
                }
                
            }
            cout << "Current Scores: \n";
            display_result(score_1, score_2);

            cout << "\n";
            
            display_game_matrix(game_matrix);
            cout << "\n";

            cout << "\n";

            if ( is_filled_game_matrix(game_matrix) )
            {
                cout << "Game Ends." << endl;
                

                return 0;
            }
            
        }

    } else
    {
        cout << "Game End." << endl;
    }

    
    return 0;
}