package(default_visibility = ["//visibility:public"])

cc_library(
    name = "colour",
    srcs = ["colour.cpp"],
    hdrs = ["colour.h"],
    deps = [
        "//math:utils"
    ]
)

cc_test(
    name = "colour_test",
    srcs = ["colour_test.cpp"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":colour",
        "//math:utils",
    ]
)
