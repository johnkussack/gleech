function parseProp(path)
        b = BinaryWalker.create()
 
        b:readData(path)
 
        b:seekToStr("DIMS")
        b:seek(8)
 
        local dims = {}
 
        for v = 1, 6, 1 do
                local dim = b:getFloat()
                table.insert(dims, dim)
        end
 
        -- Skip to texture info
        b:seek(12)
 
        local textCount = b:getInt32()
        local textures = {}
 
        print ("TC",textCount)
 
        for v = 1, textCount, 1 do
                local text = b:getBlob(4)
                table.insert(textures, text)
        end
 
        -- Skip MESH+pointer
        b:seek(8);
 
        local meshCount = b:getInt32()
 
        print ("MESHCOUNT",meshCount)
 
        for v = 1, meshCount, 1 do
 
                b:seek(4) -- Skip SMSH
                local meshWHOLEDATASize = b:getInt32()
                b:seek(4) --Skip data
               
                -- ignored blob
                local meshBlob = b:getBlob(0x20)
               
                -- Prepare to do zlib:uncompress(MESHCHUNK)
                local zlibBufferSize = b:getInt32()
                --unsigned char* zlibBuffer = new unsigned char[zlibBufferSize];
               
                local meshZlibSize = b:getInt32()
                local meshZlibBlob = b:getBlob(meshZlibSize)
               
                -- Decompress
                stream = zlib.inflate()
                inflated, eof, bytes_in, bytes_out = stream(meshZlibBlob)
               
                -- Create new binaryWalker (or reuse an old one apart from B)
                local bm = BinaryWalker.create()
                bm:setData(inflated)           
               
                local meshChunkLength = bm:getInt32()
                local meshVerticesCount = bm:getInt32()
                local triangleCount = bm:getInt32()
                bm:seek(4)
                --local unknown = bm:getBlob(8) --
               
                local verts = {}
                local triangles = {}
               
                for v2 = 1,meshVerticesCount,1 do
               
                        -- Mesh creation
                        local vert={}
 
                        table.insert(vert, -1 * bm:getFloat() / 100.0)
                        table.insert(vert, bm:getFloat() / 100.0)
                        table.insert(vert, bm:getFloat() /100.0)
 
                        table.insert(vert, bm:getFloat())
                        table.insert(vert, bm:getFloat())
                        table.insert(vert,bm:getFloat())
 
                        table.insert(vert,1.0)
                        table.insert(vert,0.0)
                        table.insert(vert,0.0)
 
                        table.insert(vert,bm:getFloat())
                        table.insert(vert,(1.0 - bm:getFloat()) ) -- Reverse DDS V from directX to openGL
                       
                        table.insert(verts,vert)
                end
               
                for v2 = 1, triangleCount,1 do
                        local triangle={}
                        table.insert(triangle,bm:getInt16())
                        table.insert(triangle,bm:getInt16())
                        table.insert(triangle,bm:getInt16())
                        table.insert(triangles,triangle)
                end
               
        end
 
end
 
if BinaryWalker == nil then
        print ("Requesting Binary walker")
        require("bw")
        require("zlib")
       
end
parseProp("/data/t.prop")