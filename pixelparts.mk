$(call inherit-product, vendor/google/pixelparts/powershare/device.mk)
$(call inherit-product, vendor/google/pixelparts/touch/device.mk)

# Parts
PRODUCT_PACKAGES += \
    GoogleParts \
    PixelFrameworksOverlay
