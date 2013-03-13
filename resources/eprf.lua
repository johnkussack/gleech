function parseEprf(path)
	b = BinaryWalker.create()
	bm = BinaryWalker.create()

	b:readData(path)

	b:seekToStr("MESH")
	
	local parsing = 1
	
	local meshes={} -- meshes storage
	
	while parsing==1 do
	
		local meshLength = b:getInt32()
		b:seek(4)
		
		local meshData = b:getBlob(meshLength)
		
		-- this may cause errors
		
		--if meshLength>=0x100 then
		
			local mesh={} -- mesh object
		
			bm:setData(meshData)
			
			bm:seek(4) --size
			bm:seek(4) --size
			bm:seek(4) --FFFFFFFF
			bm:seek(4) --size not wanted
		
			local verticesCount = bm:getInt32()
			local triangleCount = bm:getInt32()
			local unknown = bm:getInt32()
			
			local verts = {} -- verts storage
			local triangles = {} -- triangles storage
			
			for v = 1,verticesCount,1 do
				local vert = {} -- vert object
				
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
			table.insert(mesh,verts)
			
			for v = 1, triangleCount,1 do
				local triangle={}
				table.insert(triangle,bm:getInt16())
				table.insert(triangle,bm:getInt16())
				table.insert(triangle,bm:getInt16())
				table.insert(triangles,triangle)
			end
			
			
			table.insert(mesh,triangles)
			
			table.insert(meshes,mesh)
		--end
		
		-- end of may do stuff wrongly
		
		if not (check=="MESH") then
			parsing = 0
		end
	
	end
	
	return meshes

end

if BinaryWalker == nil then
	print ("Requesting Binary walker")
	require("bw")	
end
local eprfM = parseEprf("/data/p.eprf")

print ("Meshes:",table.getn(eprfM))
print ("Mesh 1 verts:",table.getn(eprfM[1][1]))
print ("Mesh 1 tri:",table.getn(eprfM[1][2]))