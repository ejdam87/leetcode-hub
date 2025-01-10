class Solution:

    def __init__( self ) -> None:
        self.pos = 0
        self.expr = ""

    def eof( self ) -> bool:
        return self.pos >= len( self.expr )

    def load_num( self ) -> int:

        sn = ""
        while not self.eof() and self.expr[ self.pos ].isdigit():
            sn += self.expr[ self.pos ]
            self.pos += 1
        
        return int( sn )

    def eval_expr( self ) -> int:

        vals = []
        while not self.eof():
            if self.expr[ self.pos ] == "(":
                self.pos += 1
                vals.append( self.eval_expr() )

            elif self.expr[ self.pos ] == ")":
                self.pos += 1
                return vals[0]

            elif self.expr[ self.pos ].isdigit():
                vals.append( self.load_num() )
            
            elif self.expr[ self.pos ]  == "-":
                if len( vals ) == 0:
                    self.pos += 1
                    b = None
                    if self.expr[ self.pos ] == "(":
                        self.pos += 1
                        b = self.eval_expr()
                    else:
                        b = self.load_num()
                    vals.append( -b )

                else:
                    a = vals.pop()
                    self.pos += 1
                    b = None
                    if self.expr[ self.pos ] == "(":
                        self.pos += 1
                        b = self.eval_expr()
                    else:
                        b = self.load_num()

                    vals.append( a - b )

            elif self.expr[ self.pos ] == "+":
                a = vals.pop()
                self.pos += 1
                b = None
                if self.expr[ self.pos ] == "(":
                    self.pos += 1
                    b = self.eval_expr()
                else:
                    b = self.load_num()

                vals.append( a + b )

        return vals[0]

    def calculate(self, s: str) -> int:
        self.expr = s.replace( " ", "" )
        return self.eval_expr()

print( Solution().calculate( "(7)-(0)+(4)" ) )
