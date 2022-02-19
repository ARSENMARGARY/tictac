#include "prototype.h"
#include <iostream>

Game::Game()
{
    arr = new Character* [board_size];
    for(int i{}; i < board_size; ++i)
    {
        arr[i] = new Character[board_size];
    }
}

Game::~Game()
{
    std::cout << "Game is finished" << std::endl;
    for(int i{}; i < board_size; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void Game::print()
{
    for(int i = 0; i < 3;i++)
    {
        for(int j = 0; j < 3;j++)
        {
            std::cout << "|" << arr[i][j].get_char() << "|" ;
        }                       
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Game::check_step(int x, int y)
{
    if(x > 3 || x < 0 || y > 3 || y < 0 )
    {
        std::cout << "\n Invalid step \n" ;
        return false;
    }
    else if(arr[x][y].get_char() == 'X' || arr[x][y].get_char() == 'O')
    {
        std::cout << "\n Invalid step \n";
        return false ;
    } 
    else
    {
        return true ;
    }
}

bool Game::check_win()
{
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 1;++j)
        {       
            if(arr[i][j].get_char() != '-' && arr[i][j + 1].get_char() != '-' && arr[i][j + 2].get_char() != '-')
            {
                if(arr[i][j].get_char() == arr[i][j + 1].get_char() && arr[i][j + 1].get_char() == arr[i][j + 2].get_char())
                {
                    std::cout << arr[i][j].get_char() << " WON ";
                    return false;
                }
            }
            if(i == j)
            {
                if(arr[i][j].get_char() != '-' && arr[i + 1][j + 1].get_char() != '-' && arr[i + 2][j + 2].get_char() != '-')
                {
                    if(arr[i][j].get_char() == arr[i + 1][j + 1].get_char() && arr[i + 1][j + 1].get_char() == arr[i + 2][j + 2].get_char())
                    {
                        std::cout << arr[i][j].get_char() << " WON ";
                        return false;
                    }
                }
            }
                if(i == 3 - j - 1)
                {
                    if(arr[i][j].get_char() != '-' && arr[i - 1][j + 1].get_char() != '-' && arr[i - 2][j + 2].get_char() != '-')
                    {
                        if(arr[i][j].get_char() == arr[i - 1][j + 1].get_char() && arr[i - 1][j + 1].get_char() == arr[i - 2][j + 2].get_char()) {
                        std::cout << arr[i][j].get_char() << " WON ";
                        return false;
                    }
                }
            }
            if(arr[j][i].get_char() != '-' && arr[j + 1][i].get_char() != '-' && arr[j + 2][i].get_char() != '-')
            {
                if(arr[j][i].get_char() == arr[j + 1][i].get_char() && arr[j + 1][i].get_char() == arr[j + 2][i].get_char())
                {
                std::cout << arr[j][i].get_char() << " WON " ;
                return false;
                }
            }
        }
    }
    return true;
}

void Game::play()
{
    int x{};
    int y{};
    char null;
    bool step = true;
    bool flag = true;
    while(flag)
    {
        print();
        std::cin >> x >> y;
        if(check_step(x,y))
        {
            if(step)
            {
                null = 'X';
                step = false;
            }
            else{
                null = 'O';
                step = true;
            }
                put(x - 1, y - 1, null);
            
           // flag = check_win();
            system("clear");
        }
        
    }
}


void Game::put(int x, int y, char sym)
{
    if(sym == 'X' || sym == 'O')
    {
        Character character_object(x,y,sym);
        arr[x][y] = character_object;
    }
    std::cout << std::endl;
    print();
}





Character::Character()
{
    this->m_null = '-' ;
}

Character::Character(int x,int y,char null)
{
    this->m_x = x;
    this->m_y = y;
    this->m_null = null;
}

char Character::get_char()
{
    return this->m_null;
}

void Character::set_char(char ch)
{
    this->m_null = ch;
}