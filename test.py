import sys
import platform

# 1. 检查版本（应该是你刚装的 3.11 或 3.12，绝不是系统自带的 3.9）
print(f"Python 版本: {sys.version}")
print(f"运行平台: {platform.platform()}")

# 2. 检查路径（路径里应该包含 /opt/homebrew 或 .local/share/mise）
print(f"当前解释器路径: {sys.executable}")

# 3. 尝试进行一个简单的计算
a = 10
b = 20
print(f"计算测试: {a} + {b} = {a + b}")

print("\n✅ 如果你看到这些信息，说明 Python 环境已经通电！")