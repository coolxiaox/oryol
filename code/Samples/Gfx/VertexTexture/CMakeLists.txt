fips_begin_app(VertexTexture windowed)
    fips_files(VertexTexture.cc VertexTexture.jpg shaders.py shaders.shd)
    fips_deps(Gfx Time Dbg)
    oryol_add_web_sample(VertexTexture "Vertex texture fetch from offscreen render target" "emscripten,android,pnacl" VertexTexture.jpg "Gfx/VertexTexture/VertexTexture.cc")
fips_end_app()
