
class Solution:
    def simplifyPath(self, path: str) -> str:

        p = ""
        for c in path:
            if len(p) == 0 or (c != "/" or p[-1] != "/"):
                p += c
        
        if p == "/":
            return p
        
        if p[-1] == "/":
            p = p[:-1]

        elems = p.split("/")
        stack = []

        for elem in elems[1:]:

            if elem == "..":
                if len(stack) > 0:
                    stack.pop()
            elif elem != ".":
                stack.append( elem )
        
        return "/" + "/".join( stack )


print( Solution().simplifyPath( "/home////ahoj///cica//c" ) )
