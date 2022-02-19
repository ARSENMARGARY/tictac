const int board_size = 3;

class Character
{
public:
    Character();
    Character(int,int,char);
public:
    char get_char();
    void set_char(char);
protected:
    int m_x{};
    int m_y{};
    char m_null{};
};

class Game
{
public:
    Game();
    ~Game();
public:
    void print();
    bool check_step(int,int);
    bool check_win();
    void play();
    void put(int,int,char);
private:
    Character ** arr;
};



