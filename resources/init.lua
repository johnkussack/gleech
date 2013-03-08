print ("Initializing Lunaloader")
lunaloader = LunaLoader(loader)

print ("Initializing shaders")
a = "/root/workspace/gleech/resources/shaders/shader.vert"
b = "/root/workspace/gleech/resources/shaders/shader.frag"
c = "/root/workspace/gleech/resources/shaders/textureshader.vert"
d = "/root/workspace/gleech/resources/shaders/textureshader.frag"
lunaloader:InitShaders(a,b,c,d)

print ("Initializing Textures")

lunaloader:LoadTexture("/root/workspace/gleech/resources/sl_church_tex02.dds",0)
lunaloader:LoadTexture("/root/workspace/gleech/resources/texture.jpg",0)
lunaloader:LoadTexture("/root/workspace/gleech/resources/aban_van.dds",0)
lunaloader:LoadTexture("/root/workspace/gleech/resources/BMBody.dds",0)
--lunaloader:LoadTexture("/root/voxel/opengl3/skybox.jpg",1)

print ("Initializing Primitives")
lunaloader:InitPrimitives()

print ("Adding Primitives")
--lunaloader:AddPrimitive(1,0,90,1,90,0,0,0) -- Plane
--lunaloader:AddPrimitive(3,-1,100,100,100,0,0,0) --Skybox

print ("Initializing MXO MGAs")
--lunaloader:AddMxoMga("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/characters/big_male/geometry/BMTorso.mga",2,0,0,0)

print ("Initializing MXO Props")
--base = "/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/props"

--lunaloader:AddMxoProp(base.."/church/holywater/default/holywater.prop",0,{1,1,1},{0,0,0},{0,0,0})
--lunaloader:AddMxoProp(base.."/church/altar_table/default/altar_table.prop",0,{1,1,1},{0,0,0},{0,0.25,-3})
--lunaloader:AddMxoProp(base.."/church/pulpit/default/pulpit.prop",0,{1,1,1},{0,180,0},{2.5,0.25,-3})

--lunaloader:AddMxoProp(base.."/church/chair/default/church_chair.prop",0,{1,1,1},{0,90,0},{4,0,3})
--lunaloader:AddMxoProp(base.."/church/chair/default/church_chair.prop",0,{1,1,1},{0,-90,0},{-4,0,3})
--lunaloader:AddMxoProp(base.."/church/pew/default/pew_5m.prop",0,{1,1,1},{0,0,0},{0,0.25,3})

--lunaloader:AddMxoProp(base.."/church/chair/default/church_chair.prop",0,{1,1,1},{0,90,0},{4,0,5})
--lunaloader:AddMxoProp(base.."/church/chair/default/church_chair.prop",0,{1,1,1},{0,-90,0},{-4,0,5})
--lunaloader:AddMxoProp(base.."/church/pew/default/pew_5m.prop",0,{1,1,1},{0,0,0},{0,0.25,5})

--lunaloader:AddMxoProp(base.."/church/chair/default/church_chair.prop",0,{1,1,1},{0,90,0},{4,0,7})
--lunaloader:AddMxoProp(base.."/church/chair/default/church_chair.prop",0,{1,1,1},{0,-90,0},{-4,0,7})
--lunaloader:AddMxoProp(base.."/church/pew/default/pew_5m.prop",0,{1,1,1},{0,0,0},{0,0.25,7})

base = "/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/prefab_database/building_shells/sl"
lunaloader:AddMxoEprf(base.."/sl_church01/sl_church01.eprf",0,{1,1,1},{0,180,0},{0,0,-40})

base = "/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/prefab_database/building_shells/metacortex"
lunaloader:AddMxoEprf(base.."/meta_sky01_lvl1.eprf",1,{1,1,1},{0,0,0},{0,0,0})
lunaloader:AddMxoEprf(base.."/meta_sky01_lvl2.eprf",1,{1,1,1},{0,0,0},{0,40,0})
lunaloader:AddMxoEprf(base.."/meta_sky01_lvl3.eprf",1,{1,1,1},{0,0,0},{0,80,0})

--lunaloader:AddMxoEprf(base.."/sl_aprt02/sl_aprt02_s07.eprf",0,{1,1,1},{0,0,0},{0,0,-40})

--lunaloader:AddMxoIprf("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/prefab_database/floors/sl/sl_church01/sl_church01_aud_01_mara.iprf",0,{1,1,1},{0,0,0},{-5,0,10})
--lunaloader:AddMxoIprf("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/prefab_database/floors/sl/sl_church01/sl_church01_aud_03.iprf",0,{1,1,1},{0,0,0},{5,0,5})
--lunaloader:AddMxoIprf("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/prefab_database/floors/sl/sl_church01/sl_church01_strw.iprf",0,{1,1,1},{0,0,0},{0,0,0})







