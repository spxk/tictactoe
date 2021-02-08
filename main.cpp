/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: triegebauer
 *
 * Created on 08. Februar 2021, 16:00
 */

#include <iostream>

using namespace std;

#define FIELD_HW 3





/*
 * Drawing the field
 */

void drawField(string** field)
{
    cout << endl;
    
    for(int x = 0; x < FIELD_HW; x++)
    {
        for(int y = 0; y < FIELD_HW; y++)
        {
            cout << field[x][y];
            
            if(y < FIELD_HW-1)
                cout << "|";
        }
        
        if(x < FIELD_HW-1)
        {
            cout << endl;
            
            for(int i = 0; i < FIELD_HW-1; i++)
                cout << "---+";
            
            cout << "---" << endl;
        }
    }
    cout << endl;
    
}





/*
 * Checking if anyone won
 */

bool checkField(string** field)
{
    bool won_x = false;
    bool won_o = false;
    int score_x = 0, score_o = 0;
    
    
    
    
    
    // Full row
    
    for(int x = 0; x < FIELD_HW; x++)
    {
        score_x = 0, score_o = 0;
        
        for(int y = 0; y < FIELD_HW; y++)
        {
            if(field[x][y] == " X ")
                score_x++;
            else if(field[x][y] == " O ")
                score_o++;
            
            if(score_x == FIELD_HW)
                won_x = true;
            else if(score_o == FIELD_HW)
                won_o = true;
        }
    }
    
    
    
    
    
    // Full column
    
    for(int y = 0; y < FIELD_HW; y++)
    {
        score_x = 0, score_o = 0;
        
        for(int x = 0; x < FIELD_HW; x++)
        {
            if(field[x][y] == " X ")
                score_x++;
            else if(field[x][y] == " O ")
                score_o++;
            
            if(score_x == FIELD_HW)
                won_x = true;
            else if(score_o == FIELD_HW)
                won_o = true;
        }
    }
    
    
    
    
    
    // Full dioagonal
    
    score_x = 0, score_o = 0;
    
    for(int x = 0; x < FIELD_HW; x++)
    {
        if(field[x][x] == " X ")
            score_x++;
        else if(field[x][x] == " O ")
            score_o++;
            
        if(score_x == FIELD_HW)
            won_x = true;
        else if(score_o == FIELD_HW)
            won_o = true;
    }
    
    score_x = 0, score_o = 0;
    
    for(int x = 0; x < FIELD_HW; x++)
    {
        if(field[(FIELD_HW-1) - x][x] == " X ")
            score_x++;
        else if(field[(FIELD_HW-1) - x][x] == " O ")
            score_o++;
            
        if(score_x == FIELD_HW)
            won_x = true;
        else if(score_o == FIELD_HW)
            won_o = true;
    }
    
    
    
    
    
    // Check who won
    
    if(won_x)
    {
        cout << endl << "Spieler 1 hat gewonnen!" << endl;
        return true;
    }
    else if(won_o)
    {
        cout << endl << "Spieler 2 hat gewonnen!" << endl;
        return true;
    }
    else
    {
        return false;
    }
}





/*
 * Initialize the field with empty values
 */

string** genField()
{
    string** field;
    
    field = new string*[FIELD_HW];
    
    for(int x = 0; x < FIELD_HW; x++)
    {
        field[x] = new string[FIELD_HW];
        
        for(int y = 0; y < FIELD_HW; y++)
        {
            field[x][y] = "   ";
        }
    }
    
    return field;
}





/*
 * Main
 */

int main()
{
    string** field = genField();
    
    int row = 0, col = 0;
    
    while(true)
    {
        drawField(field);
        
        if(checkField(field))
            break;
        
        row = 0, col = 0;
        
        // Player 2 input
        
        do
        {
            cout << endl << "(Spieler 1) Zeile: ";
            cin >> row;
            cout << "(Spieler 1) Spalte: ";
            cin >> col;
        } while(!(row < FIELD_HW+1 && row > 0) || !(col < FIELD_HW+1 && col > 0) || (field[row-1][col-1] == " X ") || (field[row-1][col-1] == " O "));
        
        field[row-1][col-1] = " X ";
        drawField(field);
        
        if(checkField(field))
            break;
        
        // Player 1 input
        
        do
        {
            cout << endl << "(Spieler 2) Zeile: ";
            cin >> row;
            cout << "(Spieler 2) Spalte: ";
            cin >> col;
        } while(!(row < FIELD_HW+1 && row > 0) || !(col < FIELD_HW+1 && col > 0) || (field[row-1][col-1] == " X ") || (field[row-1][col-1] == " O "));
        
        field[row-1][col-1] = " O ";
    }
    
    return 0;
}