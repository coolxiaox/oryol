fips_begin_app(DrawCallPerf windowed)
    fips_files(DrawCallPerf.cc DrawCallPerf.jpg shaders.py shaders.shd)
    fips_deps(Gfx Time Dbg Input)
    oryol_add_web_sample(DrawCallPerf "Measure draw call performance" "emscripten,pnacl,android" DrawCallPerf.jpg "Gfx/DrawCallPerf/DrawCallPerf.cc")
fips_end_app()
