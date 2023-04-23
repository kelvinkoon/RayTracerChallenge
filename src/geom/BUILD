package(default_visibility = ["//visibility:public"])

cc_library(
    name = "tuple",
    srcs = ["tuple.cpp"],
    hdrs = ["tuple.h"],
    deps = [
        "//math:utils"
    ]
)

cc_test(
    name = "tuple_test",
    srcs = ["tuple_test.cpp"],
    deps = ["@com_google_googletest//:gtest_main",
            ":tuple"]
)
