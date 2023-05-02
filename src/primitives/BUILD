package(default_visibility = ["//visibility:public"])

cc_library(
    name = "tuple",
    srcs = ["tuple.cpp"],
    hdrs = ["tuple.h"],
    deps = [
        ":math"
    ]
)

cc_test(
    name = "tuple_test",
    srcs = ["tuple_test.cpp"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":tuple",
        "//test_utils:test_utils"
    ]
)

cc_library(
    name = "math_constants",
    hdrs = ["math_constants.h"],
)

cc_library(
    name = "math",
    srcs = ["math.cpp"],
    hdrs = ["math.h"],
    deps = [
        ":math_constants"
    ]
)

cc_test(
    name = "math_test",
    srcs = ["math_test.cpp"],
    deps = [
        "@com_google_googletest//:gtest_main",
            ":math"
    ]
)

cc_library(
    name = "colour",
    srcs = ["colour.cpp"],
    hdrs = ["colour.h"],
    deps = [
        "math"
    ]
)

cc_test(
    name = "colour_test",
    srcs = ["colour_test.cpp"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":colour",
        "//test_utils:test_utils"
    ]
)
