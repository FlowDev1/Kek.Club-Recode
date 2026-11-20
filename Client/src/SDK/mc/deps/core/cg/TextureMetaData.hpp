#pragma once

namespace cg {
    struct TextureMetaData {
        enum class ColorSpace {
            ColorSpace_Gamma,
            ColorSpace_Linear
        };

        enum class Dimension {
            Dimension_2D,
            Dimension_3D,
            Dimension_Cube
        };

        enum class FilterMode {
            Filter_Point,
            Filter_Linear,
            Filter_Anisotropic
        };

        enum class WrapMode {
            WrapMode_Clamp,
            WrapMode_Wrap,
            WrapMode_Mirror
        };

        FilterMode filterMin;
        FilterMode filterMag;
        FilterMode filterMip;
        ColorSpace colorSpace;
        Dimension dimension;
        WrapMode wrapU;
        WrapMode wrapV;
        int numSlices;
    };
}
