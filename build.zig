const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "check",
        .target = target,
        .optimize = optimize,
    });
    exe.addCSourceFile(.{ .file = b.path("main.c") });
    exe.addWin32ResourceFile(.{ .file = b.path("resource.rc") });
    exe.linkLibC();

    b.installArtifact(exe);
}
