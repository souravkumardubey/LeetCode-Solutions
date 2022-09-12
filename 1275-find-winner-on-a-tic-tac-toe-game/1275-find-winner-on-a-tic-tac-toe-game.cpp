class Solution {
    
    bool won(vector < vector < int > > board, int val) {
        
        if ( (board[0][0] == val and board[0][1] == val and board[0][2] == val) ||
           
           ( board[0][0] == val and board[1][0] == val and board[2][0] == val) ||
            
           ( board[1][0] == val and board[1][1] == val and board[1][2] == val ) || 
            
            ( board[2][0] == val and board[2][1] == val and board[2][2] == val ) ||
            
            ( board[0][1] == val and board[1][1] == val and board[2][1] == val) ||
            
            ( board[0][2] == val and board[1][2] == val and board[2][2] == val) ||
            
            ( board[0][0] == val and board[1][1] == val and board[2][2] == val) ||
            
            ( board[0][2] == val and board[1][1] == val and board[2][0] == val )
            
           ) return true;
        
        return false;
        
    }
    
public:
    string tictactoe(vector<vector<int>>& moves) {
        
        vector < pair < int , int > > X, O;
        
        for ( int i = 0 ; i < moves.size() ; i++ ) {
            
            if ( !(i & 1) ) X.push_back({moves[i][0],moves[i][1]});
            else O.push_back({moves[i][0],moves[i][1]});
            
        }
        
        vector < vector < int > > board(9, vector < int > (9 , -1));
        
        for ( auto i : X ) board[i.first][i.second] = 1;
        
        if ( won(board , 1) ) return "A";
        
        for ( auto i : O ) board[i.first][i.second] = 0;
        
        if ( won(board,0) ) return "B";
        
        if ( moves.size() == 9 ) return "Draw";
        
        return "Pending";
        
    }
};