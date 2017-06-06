///We, Arvin Arbuis, Sram J Isle Santillan, and Cedez Marie Gulanne, upon our honor, swear that we have made this mp all by ourselves.
#include <SFML/Graphics.hpp>
#include "SnakesLadders.cpp"                //class implementation
#include <time.h>
#include <windows.h>

using namespace std;

int main(){
    SnakeLadder game;                       //is the most essential part of the whole game
    srand( time(NULL));
    int mode = 3, random, flag=0;           //modes for the shifts of the number of players, 'random' as variable for the random generated value, flag for the different phases of the window
    coordinate current, a;                  //coordinates
    sf::RenderWindow window(sf::VideoMode(550,352), "Snakes and Ladders");      //construction of window
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")){   //font for texts
        cout<<"Way font??"<<endl;
        return 1;
    }
    sf::Texture texture, dice, welcome, howTo, title, play, winner[3], background;
    if(!background.loadFromFile("background.png")){     //blue background
        cout<<"Ambot!!!";
        return 1;
    }
    if(!winner[2].loadFromFile("winner3.png")){         //if the winner is p3
        cout<<"Ambot!!!";
        return 1;
    }
    if(!winner[1].loadFromFile("winner2.png")){         //if the winner is p2
        cout<<"Ambot!!!";
        return 1;
    }
    if(!winner[0].loadFromFile("winner1.png")){         //if the winner is p1
        cout<<"Ambot!!!";
        return 1;
    }
    if(!play.loadFromFile("player.png")){               //for selection of how many players
        cout<<"Ambot!!!";
        return 1;
    }
    if(!title.loadFromFile("titleS.png")){              //title
        cout<<"Ambot!!!";
        return 1;
    }
    if(!welcome.loadFromFile("snake.png")){             //menu
        cout<<"Ambot!!!";
        return 1;
    }
    if(!howTo.loadFromFile("how.png")){                 //how to play
        cout<<"Ambot!!!";
        return 1;
    }
    if(!texture.loadFromFile("bitin.png")){             //snake and ladder board
        cout<<"Ambot!!!";
        return 1;
    }
    if(!dice.loadFromFile("dice.png")){                 //diceeeee
        cout<<"Ambot!!!";
        return 1;
    }
    sf::Sprite sprite(texture), dsprite(dice), welc(welcome), hwTo(howTo), tit(title), pl(play), win, drop(background); //because i cant draw textures in the window
    tit.setPosition(sf::Vector2f(352,-5));                      //title should be placed on the upper right corner of the window beside the board
    dsprite.setTextureRect(sf::IntRect(1, 1, 100, 100));        //certain portion of the dice sprite image
    dsprite.setPosition(sf::Vector2f(400, 220));                //position is on the lower right
    float x=10.f, y=10.f;                                       //initial position value
    sf::Text text[3], mov;                              //texts for the players and 'mov' for the messages while the game is ongoing
    for(int i=0; i<mode; i++){
        text[i].setCharacterSize(20);                   //texts have the same character size and font
        text[i].setFont(font);
    }

    text[0].setColor(sf::Color::Blue);                  //player 1 is blue
    text[0].setString("Player 1");
    text[0].setPosition(410,100);
    text[1].setColor(sf::Color::Red);                   //player 2 is red
    text[1].setString("Player 2");
    text[1].setPosition(410,120);
    text[2].setColor(sf::Color::Yellow);                //player 3 is yellow
    text[2].setString("Player 3");
    text[2].setPosition(410,140);

    mov.setCharacterSize(17);
    mov.setColor(sf::Color::Black);                     //messages are written in black
    mov.setFont(font);
    mov.setPosition(360,170);

    sf::CircleShape shape[3];                           //three circles for the 3 players
    for(int i=0; i<mode; i++){
        shape[i].setRadius(10.f);
        shape[i].setPosition(x,y);
    }
    shape[0].setFillColor(sf::Color::Blue);
    shape[1].setFillColor(sf::Color::Red);
    shape[2].setFillColor(sf::Color::Yellow);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){                 //check all the window's events that were triggered since the last iteration of the loop
            if(event.type == sf::Event::Closed)         // "close requested" event: we close the window
                window.close();
            if(flag == 0){
                window.clear(sf::Color::Black);
                window.draw(welc);                      //welcome phase and menu
                window.display();
                if(event.mouseButton.button == sf::Mouse::Left){
                    cout<<event.mouseButton.x<<" "<<event.mouseButton.y<<endl;
                    if(event.mouseButton.x>=289&&event.mouseButton.x<=455&&event.mouseButton.y>=108&&event.mouseButton.y<=144)
                        flag = 1;                       //if the player wants to play
                    if(event.mouseButton.x>=289&&event.mouseButton.x<=455&&event.mouseButton.y>=172&&event.mouseButton.y<=210)
                        flag = 2;                       //the player dont know how to play
                    if(event.mouseButton.x>=289&&event.mouseButton.x<=455&&event.mouseButton.y>=234&&event.mouseButton.y<=270)
                        window.close();                 //wants to exit
                }
            }
            if(flag == 1){
                window.clear(sf::Color::Black);
                window.draw(pl);                        //number of players selection
                window.display();
                if(event.mouseButton.button == sf::Mouse::Left){
                    cout<<event.mouseButton.x<<" "<<event.mouseButton.y<<endl;
                    if(event.mouseButton.x>=194&&event.mouseButton.x<=362&&event.mouseButton.y>=122&&event.mouseButton.y<=158){
                        game.setter(2);                 //two players
                        mode = 2;
                        flag = 3;
                    }
                    if(event.mouseButton.x>=194&&event.mouseButton.x<=362&&event.mouseButton.y>=188&&event.mouseButton.y<=225){
                        game.setter(3);                 //three players
                        mode = 3;
                        flag = 3;
                    }
                    if(event.mouseButton.x>=30&&event.mouseButton.x<=114&&event.mouseButton.y>=290&&event.mouseButton.y<=320)
                        flag = 0;                       //back to menu
                }
            }
            if(flag == 2){
                window.clear(sf::Color::Black);
                window.draw(hwTo);                      //display "how to play"
                window.display();
                if(event.mouseButton.button == sf::Mouse::Left){
                    cout<<event.mouseButton.x<<" "<<event.mouseButton.y<<endl;
                    if(event.mouseButton.x>=27&&event.mouseButton.x<=111&&event.mouseButton.y>=293&&event.mouseButton.y<=325)
                        flag = 0;                       //back to menu
                    if(event.mouseButton.x>=419&&event.mouseButton.x<=504&&event.mouseButton.y>=293&&event.mouseButton.y<=325)
                        flag = 1;                       //play
                }
            }
            if(flag==3){                            //game proper
                if(game.checkWinner()!=0){          //if there is already a winner
                    window.clear(sf::Color::White);
                    win.setTexture(winner[game.checkWinner()-1]);
                    window.draw(win);
                    window.display();
                    if(event.mouseButton.button == sf::Mouse::Left){
                        cout<<event.mouseButton.x<<" "<<event.mouseButton.y<<endl;
                        if(event.mouseButton.x>=194&&event.mouseButton.x<=363&&event.mouseButton.y>=274&&event.mouseButton.y<=311)
                            flag = 0;           //back to menu
                    }
                }
                else{
                    current = game.getPos();
                    a = SnaOrLad(current);
                    if(current.x != a.x){
                        game.setCell(a.x,a.y);
                        if(a.x>current.x){          //when the position of a player is lower than the current move
                            if(game.getPlayer()==1)
                                mov.setString("  A Snake bit Player 1!");
                            if(game.getPlayer()==2)
                                mov.setString("  A Snake bit Player 2!");
                            if(game.getPlayer()==3)
                                mov.setString("  A Snake bit Player 3!");
                        }
                        if(a.x<current.x){          //when the position of a player is higher than the current move
                            if(game.getPlayer()==1)
                                mov.setString("Player 1 found a Ladder!");
                            if(game.getPlayer()==2)
                                mov.setString("Player 2 found a Ladder!");
                            if(game.getPlayer()==3)
                                mov.setString("Player 3 found a Ladder!");
                        }
                        window.clear(sf::Color::White);
                        window.draw(drop);              //draw the background
                        window.draw(sprite);            //draw the board
                        for(int i=0; i<10; i++){
                            for(int j=0; j<10; j++){
                                if(game.content(j,i)==2)
                                    shape[1].setPosition(10+i*35,10+j*35);
                                if(game.content(j,i)==1)
                                    shape[0].setPosition(10+i*35,10+j*35);
                                if(game.content(j,i)==3)
                                    shape[2].setPosition(10+i*35,10+j*35);              //set the position of the shapes according to the game board
                                if(game.content(j,i)==4){
                                    shape[0].setPosition(10+i*35-5,10+j*35-5);
                                    shape[1].setPosition(10+i*35+5,10+j*35+5);
                                }
                                if(game.content(j,i)==5){
                                    shape[0].setPosition(10+i*35-5,10+j*35-5);
                                    shape[2].setPosition(10+i*35+5,10+j*35+5);
                                }
                                if(game.content(j,i)==6){
                                    shape[1].setPosition(10+i*35-5,10+j*35-5);
                                    shape[2].setPosition(10+i*35+5,10+j*35+5);
                                }
                                if(game.content(j,i)==7){
                                    shape[0].setPosition(10+i*35-5,10+j*35-5);
                                    shape[1].setPosition(10+i*35+5,10+j*35-5);
                                    shape[2].setPosition(10+i*35,10+j*35+5);
                                }
                            }
                        }
                        for(int i=0; i<mode; i++)
                            window.draw(shape[i]);              //draw the circles
                        window.draw(dsprite);
                        for(int i=0; i<mode; i++)
                            window.draw(text[i]);               //draw the texts
                        window.draw(mov);                       //message
                        window.draw(tit);                       //draw the title
                        window.display();                       //display the whole window
                        Sleep(1500);
                    }
                    if(mode == 3){                  //if there are three players
                        if(game.getPlayer() == 3)
                            mov.setString("  Roll the Dice Player 1!");
                        if(game.getPlayer() == 1)               //set the message of the according to the players turn
                            mov.setString("  Roll the Dice Player 2!");
                        if(game.getPlayer() == 2)
                            mov.setString("  Roll the Dice Player 3!");
                    }
                    if(mode == 2){                  //if there are three players
                        if(game.getPlayer() == 1)
                            mov.setString("  Roll the Dice Player 2!");
                        if(game.getPlayer() == 2)               //set the message of the according to the players turn
                            mov.setString("  Roll the Dice Player 1!");
                    }
                    if(event.type == sf::Event::MouseButtonPressed){
                        if(event.mouseButton.button == sf::Mouse::Left){
                            cout<<event.mouseButton.x<<" "<<event.mouseButton.y<<endl;
                            if(event.mouseButton.x>=400&&event.mouseButton.x<=500&&event.mouseButton.y>=220&&event.mouseButton.y<=320){
                                //if the player clicked the dice
                                game.setPlayer(mode);
                                random = rand()%6+1;        //random number genarator
                                for(int i=0, flag=0; i<random; i++){
                                    current = game.getPos();
                                    if(current.x==0&&current.y==0)
                                        flag = 1;
                                    if(flag==0){
                                        current = getCoor(current.x,current.y,1);
                                        game.setCell(current.x,current.y);
                                    }
                                    else
                                        game.setCell(current.x,current.y+1);
                                    dsprite.setTextureRect(sf::IntRect((random-1)*100+1, 1, 100, 100));

                                    window.clear(sf::Color::White);
                                    window.draw(drop);
                                    window.draw(sprite);
                                    for(int i=0; i<10; i++){                                        //THIS WHOLE THING SHOWS THE SHAPES TRAVERSE THROUGH THE TILES ACCORDING TO THE RANDOM NUMBER GIVEN
                                        for(int j=0; j<10; j++){
                                            if(game.content(j,i)==2)
                                                shape[1].setPosition(10+i*35,10+j*35);
                                            if(game.content(j,i)==1)
                                                shape[0].setPosition(10+i*35,10+j*35);
                                            if(game.content(j,i)==3)
                                                shape[2].setPosition(10+i*35,10+j*35);
                                            if(game.content(j,i)==4){
                                                shape[0].setPosition(10+i*35-5,10+j*35-5);
                                                shape[1].setPosition(10+i*35+5,10+j*35+5);
                                            }
                                            if(game.content(j,i)==5){
                                                shape[0].setPosition(10+i*35-5,10+j*35-5);
                                                shape[2].setPosition(10+i*35+5,10+j*35+5);
                                            }
                                            if(game.content(j,i)==6){
                                                shape[1].setPosition(10+i*35-5,10+j*35-5);
                                                shape[2].setPosition(10+i*35+5,10+j*35+5);
                                            }
                                            if(game.content(j,i)==7){
                                                shape[0].setPosition(10+i*35-5,10+j*35-5);
                                                shape[1].setPosition(10+i*35+5,10+j*35-5);
                                                shape[2].setPosition(10+i*35,10+j*35+5);
                                            }
                                        }
                                    }
                                    for(int i=0; i<mode; i++)
                                        window.draw(shape[i]);
                                    window.draw(dsprite);
                                    for(int i=0; i<mode; i++)
                                        window.draw(text[i]);
                                    window.draw(mov);
                                    window.draw(tit);
                                    window.display();
                                    Sleep(500);
                                }
                            }
                        }
                    }
                    window.clear(sf::Color::White);
                    window.draw(drop);
                    window.draw(sprite);
                    if(game.content(9,0)==4){               //if the initial value of the board is of two players
                        shape[0].setPosition(5,320);
                        shape[1].setPosition(15,330);
                    }
                    if(game.content(9,0)==7){               //if the initial value of the board is of three players
                        shape[0].setPosition(5,320);
                        shape[1].setPosition(15,320);
                        shape[2].setPosition(10,330);
                    }
                    for(int i=0; i<mode; i++)
                        window.draw(shape[i]);
                    window.draw(dsprite);
                    for(int i=0; i<mode; i++)
                        window.draw(text[i]);
                    window.draw(mov);
                    window.draw(tit);
                    window.display();
                }
            }
        }
    }
    return 0;
}
