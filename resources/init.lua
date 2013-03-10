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

print ("Initializing MXO MGAs")
--lunaloader:AddMxoMga("/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/characters/big_male/geometry/BMTorso.mga",2,0,0,0)

print ("Initializing MXO Props")


base = "/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/prefab_database/building_shells/sl"
lunaloader:AddMxoEprf(base.."/sl_church01/sl_church01.eprf",0,{1,1,1},{0,180,0},{0,0,-40})

base = "/media/B463-11BE/mxoNewStuff/mxo/Extracted/resource/prefab_database/building_shells/metacortex"
lunaloader:AddMxoEprf(base.."/meta_sky01_lvl1.eprf",1,{1,1,1},{0,0,0},{0,0,0})
lunaloader:AddMxoEprf(base.."/meta_sky01_lvl2.eprf",1,{1,1,1},{0,0,0},{0,40,0})
lunaloader:AddMxoEprf(base.."/meta_sky01_lvl3.eprf",1,{1,1,1},{0,0,0},{0,80,0})