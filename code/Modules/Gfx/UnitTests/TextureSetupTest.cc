//------------------------------------------------------------------------------
//  TextureSetupTest.cc
//------------------------------------------------------------------------------
#include "Pre.h"
#include "UnitTest++/src/UnitTest++.h"
#include "Gfx/Setup/TextureSetup.h"

using namespace Oryol;

TEST(TextureSetupTest) {
    
    // setup as absolute-size render target, no depth buffer
    auto rt = TextureSetup::RenderTarget(320, 256);
    rt.Locator = Locator("absSize");
    rt.ColorFormat = PixelFormat::RGB8;
    CHECK(!rt.ShouldSetupFromFile());
    CHECK(!rt.ShouldSetupFromImageFileData());
    CHECK(!rt.ShouldSetupFromPixelData());
    CHECK(rt.ShouldSetupAsRenderTarget());
    CHECK(!rt.IsRelSizeRenderTarget());
    CHECK(!rt.HasSharedDepth());
    CHECK(!rt.HasDepth());
    CHECK(rt.Locator.Location() == "absSize");
    CHECK(rt.Width == 320);
    CHECK(rt.Height == 256);
    CHECK(rt.RelWidth == 0.0f);
    CHECK(rt.RelHeight == 0.0f);
    CHECK(rt.ColorFormat == PixelFormat::RGB8);
    CHECK(rt.DepthFormat == PixelFormat::InvalidPixelFormat);
    CHECK(!rt.DepthRenderTarget.IsValid());
    CHECK(rt.WrapU == TextureWrapMode::ClampToEdge);
    CHECK(rt.WrapV == TextureWrapMode::ClampToEdge);
    CHECK(rt.WrapW == TextureWrapMode::InvalidTextureWrapMode);
    CHECK(rt.MagFilter == TextureFilterMode::Nearest);
    CHECK(rt.MinFilter == TextureFilterMode::Nearest);
    
    // setup as absolute-size render target, with depth buffer
    auto rt0 = TextureSetup::RenderTarget(320, 256);
    rt0.ColorFormat = PixelFormat::RGBA8;
    rt0.DepthFormat = PixelFormat::D24S8;
    CHECK(!rt0.ShouldSetupFromFile());
    CHECK(!rt0.ShouldSetupFromImageFileData());
    CHECK(!rt0.ShouldSetupFromPixelData());
    CHECK(rt0.ShouldSetupAsRenderTarget());
    CHECK(!rt0.IsRelSizeRenderTarget());
    CHECK(!rt0.HasSharedDepth());
    CHECK(rt0.HasDepth());
    CHECK(rt0.Locator == Locator::NonShared());
    CHECK(rt0.Width == 320);
    CHECK(rt0.Height == 256);
    CHECK(rt0.RelWidth == 0.0f);
    CHECK(rt0.RelHeight == 0.0f);
    CHECK(rt0.ColorFormat == PixelFormat::RGBA8);
    CHECK(rt0.DepthFormat == PixelFormat::D24S8);
    CHECK(!rt0.DepthRenderTarget.IsValid());
    CHECK(rt0.WrapU == TextureWrapMode::ClampToEdge);
    CHECK(rt0.WrapV == TextureWrapMode::ClampToEdge);
    CHECK(rt0.WrapW == TextureWrapMode::InvalidTextureWrapMode);
    CHECK(rt0.MagFilter == TextureFilterMode::Nearest);
    CHECK(rt0.MinFilter == TextureFilterMode::Nearest);
    
    // setup as relative-size render target, no depth buffer
    auto rt1 = TextureSetup::RelSizeRenderTarget(0.5f, 0.25f);
    rt1.ColorFormat = PixelFormat::R5G6B5;
    CHECK(!rt1.ShouldSetupFromFile());
    CHECK(!rt1.ShouldSetupFromImageFileData());
    CHECK(!rt1.ShouldSetupFromPixelData());
    CHECK(rt1.ShouldSetupAsRenderTarget());
    CHECK(rt1.IsRelSizeRenderTarget());
    CHECK(!rt1.HasSharedDepth());
    CHECK(!rt1.HasDepth());
    CHECK(rt1.Locator == Locator::NonShared());
    CHECK(rt1.Width == 0);
    CHECK(rt1.Height == 0);
    CHECK(rt1.RelWidth == 0.5f);
    CHECK(rt1.RelHeight == 0.25f);
    CHECK(rt1.ColorFormat == PixelFormat::R5G6B5);
    CHECK(rt1.DepthFormat == PixelFormat::InvalidPixelFormat);
    CHECK(!rt1.DepthRenderTarget.IsValid());
    CHECK(rt1.WrapU == TextureWrapMode::ClampToEdge);
    CHECK(rt1.WrapV == TextureWrapMode::ClampToEdge);
    CHECK(rt1.WrapW == TextureWrapMode::InvalidTextureWrapMode);
    CHECK(rt1.MagFilter == TextureFilterMode::Nearest);
    CHECK(rt1.MinFilter == TextureFilterMode::Nearest);
    
    // setup as relative-size render target, with depth buffer
    auto rt2 = TextureSetup::RelSizeRenderTarget(0.5f, 0.25f);
    rt2.ColorFormat = PixelFormat::RGBA4;
    rt2.DepthFormat = PixelFormat::D16;
    CHECK(!rt2.ShouldSetupFromFile());
    CHECK(!rt2.ShouldSetupFromImageFileData());
    CHECK(!rt2.ShouldSetupFromPixelData());
    CHECK(rt2.ShouldSetupAsRenderTarget());
    CHECK(rt2.IsRelSizeRenderTarget());
    CHECK(!rt2.HasSharedDepth());
    CHECK(rt2.HasDepth());
    CHECK(rt2.Locator == Locator::NonShared());
    CHECK(rt2.Width == 0);
    CHECK(rt2.Height == 0);
    CHECK(rt2.RelWidth == 0.5f);
    CHECK(rt2.RelHeight == 0.25f);
    CHECK(rt2.ColorFormat == PixelFormat::RGBA4);
    CHECK(rt2.DepthFormat == PixelFormat::D16);
    CHECK(!rt2.DepthRenderTarget.IsValid());
    CHECK(rt2.WrapU == TextureWrapMode::ClampToEdge);
    CHECK(rt2.WrapV == TextureWrapMode::ClampToEdge);
    CHECK(rt2.WrapW == TextureWrapMode::InvalidTextureWrapMode);
    CHECK(rt2.MagFilter == TextureFilterMode::Nearest);
    CHECK(rt2.MinFilter == TextureFilterMode::Nearest);
    
    // setup as shared-depth render target
    auto rt3 = TextureSetup::SharedDepthRenderTarget(Id(1, 2, ResourceType::Texture));
    rt3.ColorFormat = PixelFormat::RGBA32F;
    CHECK(!rt3.ShouldSetupFromFile());
    CHECK(!rt3.ShouldSetupFromImageFileData());
    CHECK(!rt3.ShouldSetupFromPixelData());
    CHECK(rt3.ShouldSetupAsRenderTarget());
    CHECK(!rt3.IsRelSizeRenderTarget());
    CHECK(rt3.HasSharedDepth());
    CHECK(rt3.HasDepth());
    CHECK(rt3.Width == 0);
    CHECK(rt3.Height == 0);
    CHECK(rt3.RelWidth == 0.0f);
    CHECK(rt3.RelHeight == 0.0f);
    CHECK(rt3.ColorFormat == PixelFormat::RGBA32F);
    CHECK(rt3.DepthFormat == PixelFormat::InvalidPixelFormat);
    CHECK(rt3.DepthRenderTarget.Id().SlotIndex() == 2);
    CHECK(rt3.DepthRenderTarget.Id().Type() == ResourceType::Texture);
    CHECK(rt3.DepthRenderTarget.Id().UniqueStamp() == 1);
    CHECK(rt3.WrapU == TextureWrapMode::ClampToEdge);
    CHECK(rt3.WrapV == TextureWrapMode::ClampToEdge);
    CHECK(rt3.WrapW == TextureWrapMode::InvalidTextureWrapMode);
    CHECK(rt3.MagFilter == TextureFilterMode::Nearest);
    CHECK(rt3.MinFilter == TextureFilterMode::Nearest);
}

