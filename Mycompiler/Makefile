# 设置编译器和编译选项
CXX = g++
CXXFLAGS = -Wall -Werror -Werror=return-type -Werror=non-virtual-dtor -Werror=delete-non-virtual-dtor -Werror=reorder -Werror=init-self -Werror=uninitialized -Werror=unused -Werror=sign-compare -Werror=switch -Werror=parentheses -Werror=array-bounds -Werror=pointer-arith -Werror=cast-align -Werror=cast-qual -Werror=cast-align -Werror=logical-op -Werror=init-list-lifetime -Werror=double-promotion -Werror=format=2 -Werror=format-security -Werror=format-nonliteral -Werror=missing-declarations -Werror=missing-prototypes -Werror=strict-prototypes -Werror=old-style-definition -Werror=undef -Werror=shadow -Werror=overloaded-virtual -Werror=pedantic -Werror=conversion -Werror=sign-conversion -Werror=misleading-indentation -Werror=duplicate-decl-specifier -Werror=bad-function-cast -Werror=missing-noreturn -Werror=return-type -Werror=ctor-dtor-privacy -Werror=unreachable-code -Werror=deprecated-declarations -Werror=missing-braces -Werror=unused-but-set-variable -Werror=unused-but-set-parameter -Werror=unused-variable -Werror=unused-parameter -Werror=unused-function -Werror=unused-member-function -Werror=unused-local-typedefs -Werror=unused-template -Werror=useless-cast -Werror=volatile-register-var -Werror=unknown-pragmas -Werror=system-headers -Werror=init-statics -Werror=inconsistent-missing-override -Werror=missing-override -Werror=range-loop-analysis -Werror=misleading-indentation -Werror=implicit-fallthrough=5 -Werror=invalid-offsetof -Werror=date-time -Werror=sequence-point -Werror=ignored-qualifiers -Werror=misleading-indentation -Werror=type-limits -Werror=except-type -Werror=array-bounds -Werror=vla -Werror=overflow -Werror=unsafe-loop-optimizations -Werror=float-equal -Werror=undef -Werror=init-self -Werror=unused-result -Werror=unreachable-code -Werror=unused-variable -Werror=unused-parameter -Werror=unused-function -Werror=unused-member-function -Werror=unused-local-typedefs -Werror=unused-template -Werror=useless-cast -Werror=volatile-register-var -Werror=unknown-pragmas -Werror=system-headers -Werror=init-statics -Werror=inconsistent-missing-override -Werror=missing-override -Werror=range-loop-analysis -Werror=misleading-indentation -Werror=implicit-fallthrough=5 -Werror=invalid-offsetof -Werror=date-time -Werror=sequence-point -Werror=ignored-qualifiers -Werror=misleading-indentation -Werror=type-limits -Werror=except-type -Werror=array-bounds -Werror=vla -Werror=overflow -Werror=unsafe-loop-optimizations -Werror=float-equal -Werror=undef -Werror=init-self -Werror=unused-result -Werror=unreachable-code -Werror=unused-variable -Werror=unused-parameter -Werror=unused-function -Werror=unused-member-function -Werror=unused-local-typedefs -Werror=unused-template -Werror=useless-cast -Werror=volatile-register-var -Werror=unknown-pragmas -Werror=system-headers -Werror=init-statics -Werror=inconsistent-missing-override -Werror=missing-override -Werror=range-loop-analysis -Werror=misleading-indentation -Werror=implicit-fallthrough=5 -Werror=invalid-offsetof -Werror=date-time -Werror=sequence-point -Werror=ignored-qualifiers -Werror=misleading-indentation -Werror=type-limits -Werror=except-type -Werror=array-bounds -Werror=vla -Werror=overflow -Werror=unsafe-loop-optimizations -Werror=float-equal -g -std=c++11

# 获取所有源文件
SRCS = $(wildcard *.cpp)
# 获取所有头文件
HDRS = $(wildcard *.h)
# 生成目标文件列表
OBJS = $(SRCS:.cpp=.o)
# 目标可执行文件
TARGET = Mycompiler

# 默认目标，生成可执行文件
all: $(TARGET)

# 生成可执行文件的规则
$(TARGET): $(OBJS)
    $(CXX) $(CXXFLAGS) -o $@ $^

# 生成目标文件的通用规则
%.o: %.cpp $(HDRS)
    $(CXX) $(CXXFLAGS) -c -o $@ $<

# 清理目标文件和可执行文件
clean:
    rm -f $(OBJS) $(TARGET)