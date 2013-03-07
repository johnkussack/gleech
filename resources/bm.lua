BinaryWalker = {}
BinaryWalker.__index = BinaryWalker
 
function BinaryWalker.create()
        local bw = {}             -- our new object
        setmetatable(bw,BinaryWalker)  -- make Account handle lookup
        bw.offset = 1
        bw.data = ""
        return bw
end
 
function BinaryWalker:readData(fpath)
        local f = io.open(fpath, "rb")
        local content = f:read("*all")
        f:close()
        self.data = content
end
 
function BinaryWalker:setData(val)
        self.data = val
        self.offset = 1
end
 
function BinaryWalker:seek(val)
        self.offset = self.offset + val
end
 
function BinaryWalker:seekToStr(key)
        local lkey = string.len(key) -1
        local work = 1
       
        local temp = string.sub(self.data,self.offset,self.offset+lkey)
       
        while work==1 do
                if temp == key then
                        self:seek(lkey+1)
                        work = 0
                       
                else
                        if self.offset<string.len(self.data) then
                                self:seek(1)
                                temp = string.sub(self.data,self.offset,self.offset+lkey)
                        else
                                work = 0
                        end    
                end
 
        end
       
end
 
function BinaryWalker:getOffset()
        return self.offset
end
 
function BinaryWalker:getBlob(n)
        local x = string.sub(self.data, self.offset, self.offset+n)
        self:seek(n)
        return x
end
 
function BinaryWalker:getFloat()
       
        local x = self:getBlob(4)
        local sign = 1
        local mantissa = string.byte(x, 3) % 128
        for i = 2, 1, -1 do mantissa = mantissa * 256 + string.byte(x, i) end
        if string.byte(x, 4) > 127 then sign = -1 end
        local exponent = (string.byte(x, 4) % 128) * 2 +
                   math.floor(string.byte(x, 3) / 128)
        if exponent == 0 then return 0 end
        mantissa = (math.ldexp(mantissa, -23) + 1) * sign
       
        return math.ldexp(mantissa, exponent - 127)
 
end
 
function BinaryWalker:getInt16()
        local ih = self:getBlob(2)
        local i = 0
       
        i = i + (string.byte(ih,1))
        i = i + (string.byte(ih,2)*256)
       
        return i
end
 
function BinaryWalker:getInt32()
        local ih = self:getBlob(4)
       
        local i = 0
        i = i + (string.byte(ih,1))
        i = i + (string.byte(ih,2)*256)
        i = i + (string.byte(ih,3)*65536)
        i = i + (string.byte(ih,4)*16777216)
        return i
 
end