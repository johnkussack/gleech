print ("Initializing Lunaloader")
lunaloader = LunaLoader(loader)

print ("Initializing shaders")
a = "/root/workspace/gleech/resources/shaders/shader.vert"
b = "/root/workspace/gleech/resources/shaders/shader.frag"
c = "/root/workspace/gleech/resources/shaders/textureshader.vert"
d = "/root/workspace/gleech/resources/shaders/textureshader.frag"
lunaloader:InitShaders(a,b,c,d)

print ("Initializing Textures")
lunaloader:LoadTexture("/root/workspace/gleech/resources/texture.jpg",0)
lunaloader:LoadTexture("/root/workspace/gleech/resources/aban_van.dds",0)
lunaloader:LoadTexture("/root/workspace/gleech/resources/BMBody.dds",0)
--lunaloader:LoadTexture("/root/voxel/opengl3/skybox.jpg",1)

print ("Initializing Primitives")
lunaloader:InitPrimitives()

print ("Adding Primitives")
--lunaloader:AddPrimitive(1,0,90,1,90,0,0,0) -- Plane
--lunaloader:AddPrimitive(3,-1,100,100,100,0,0,0) --Skybox

print ("Initializing MXO MXAs")
lunaloader:AddMxoMga("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/characters/big_male/geometry/BMTorso.mga",2,0,0,0)

print ("Initializing MXO Props")
lunaloader:AddMxoProp("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/props/abandoned_vehicles/van/default/van_wheelless.prop",1,{1,1,1},{0,180,0},{0,0,0})
lunaloader:AddMxoProp("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/props/toilets/regular/clean/cleantoilet.prop",0,{1,1,1},{0,0,0},{0,0,0})
lunaloader:AddMxoProp("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/props/arcade_machine/regular/default/arcade_machine.prop",0,{1,1,1},{0,0,0},{0,0,0})
lunaloader:AddMxoProp("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/props/arcade_machine/regular/default/arcade_machine2.prop",0,{1,1,1},{0,0,0},{0,0,0})
lunaloader:AddMxoProp("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/props/arcade_machine/regular/default/arcade_machine3.prop",0,{1,1,1},{0,0,0},{0,0,0})
lunaloader:AddMxoProp("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/props/vehicles/2door_coupe/default/2dr_coupe.prop",0,{1,1,1},{0,0,0},{0,0,0})
lunaloader:AddMxoProp("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/props/vehicles/2door_coupe/default/modern.prop",0,{1,1,1},{0,0,0},{0,0,0})
