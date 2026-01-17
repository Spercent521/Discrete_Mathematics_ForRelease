# 命题逻辑与谓词逻辑期末复习要点
## 一、命题逻辑基础
### 1. 命题定义与分类
- 命题：具有确切真值的陈述句，真值仅为真（1）或假（0）。
- 原子命题：不能再分解的简单命题。
- 复合命题：由原子命题通过联结词组成的命题。
- 命题常元：真值确定的命题；命题变元：真值不确定的命题（可指代任意命题）。

### 2. 命题联结词（逻辑运算符）
| 联结词 | 符号              | 含义       | 真值规则             | 日常表述                           |
| ------ | ----------------- | ---------- | -------------------- | ---------------------------------- |
| 否定   | $\neg$            | 非P        | 与P真值相反          | “非”“没有”“不是”                   |
| 合取   | $\land$           | P且Q       | 仅当P、Q均为真时为真 | “与”“且”“既…又…”“虽然…但是…”       |
| 析取   | $\lor$            | P或Q       | 仅当P、Q均为假时为假 | “或”“要么…要么…”（兼容或）         |
| 蕴含   | $\rightarrow$     | 如果P则Q   | 仅当P真Q假时为假     | “如果…就…”“只有…才…”“除非…否则非…” |
| 等价   | $\leftrightarrow$ | P当且仅当Q | P、Q真值相同时为真   | “等价”“充要条件”“反之亦然”         |

- 排斥或：$(P \land \neg Q) \lor (\neg P \land Q)$，记为$P \oplus Q$（二者不可同时成立）。
- 优先级：$() > \neg > \land > \lor > \rightarrow > \leftrightarrow$。

### 3. 命题公式与真值表
- 命题公式（合式公式）定义：
  1. 命题变元是公式；
  2. 若$\alpha$是公式，则$\neg\alpha$是公式；
  3. 若$\alpha$、$\beta$是公式，则$\alpha \lor \beta$、$\alpha \land \beta$、$\alpha \rightarrow \beta$、$\alpha \leftrightarrow \beta$是公式；
  4. 仅由有限次上述规则形成的符号串是公式。
- 子公式：公式中连续且为公式的符号串。
- 指派：对命题变元赋真值，完全指派（所有变元赋值）、部分指派（部分变元赋值）。
- 成真指派：使公式为真的指派；成假指派：使公式为假的指派。
- 真值表：列出所有完全指派及对应公式真值的表格，n个变元有$2^n$行。

### 4. 公式类型
- 永真式（重言式）：所有完全指派均为成真指派。
- 永假式（矛盾式）：所有完全指派均为成假指派。
- 可满足式：存在至少一个成真指派（永真式是特殊的可满足式）。

### 5. 等值演算
- 等值定义：$\alpha \leftrightarrow \beta$为重言式，则$\alpha \Leftrightarrow \beta$（$\alpha$与$\beta$等值）。
- 基本等值式：
  1. 双重否定律：$\alpha \Leftrightarrow \neg\neg\alpha$；
  2. 等幂律：$\alpha \Leftrightarrow \alpha \lor \alpha$、$\alpha \Leftrightarrow \alpha \land \alpha$；
  3. 交换律：$\alpha \lor \beta \Leftrightarrow \beta \lor \alpha$、$\alpha \land \beta \Leftrightarrow \beta \land \alpha$；
  4. 结合律：$(\alpha \lor \beta) \lor \gamma \Leftrightarrow \alpha \lor (\beta \lor \gamma)$、$(\alpha \land \beta) \land \gamma \Leftrightarrow \alpha \land (\beta \land \gamma)$；
  5. 分配律：$\alpha \lor (\beta \land \gamma) \Leftrightarrow (\alpha \lor \beta) \land (\alpha \lor \gamma)$、$\alpha \land (\beta \lor \gamma) \Leftrightarrow (\alpha \land \beta) \lor (\alpha \land \gamma)$；
  6. 德摩根律：$\neg(\alpha \lor \beta) \Leftrightarrow \neg\alpha \land \neg\beta$、$\neg(\alpha \land \beta) \Leftrightarrow \neg\alpha \lor \neg\beta$；
  7. 吸收律：$\alpha \lor (\alpha \land \beta) \Leftrightarrow \alpha$、$\alpha \land (\alpha \lor \beta) \Leftrightarrow \alpha$；
  8. 零一律：$\alpha \lor 1 \Leftrightarrow 1$、$\alpha \land 0 \Leftrightarrow 0$；
  9. 同一律：$\alpha \lor 0 \Leftrightarrow \alpha$、$\alpha \land 1 \Leftrightarrow \alpha$；
  10. 排中律：$\alpha \lor \neg\alpha \Leftrightarrow 1$；
  11. 矛盾律：$\alpha \land \neg\alpha \Leftrightarrow 0$；
  12. 蕴含等值式：$\alpha \rightarrow \beta \Leftrightarrow \neg\alpha \lor \beta$；
  13. 假言易位：$\alpha \rightarrow \beta \Leftrightarrow \neg\beta \rightarrow \neg\alpha$；
  14. 等价等值式：$\alpha \leftrightarrow \beta \Leftrightarrow (\alpha \rightarrow \beta) \land (\beta \rightarrow \alpha)$、$\alpha \leftrightarrow \beta \Leftrightarrow (\alpha \land \beta) \lor (\neg\alpha \land \neg\beta)$；
  15. 等价否定等值式：$\alpha \leftrightarrow \beta \Leftrightarrow \neg\alpha \leftrightarrow \neg\beta$；
  16. 归谬论：$(\alpha \rightarrow \beta) \land (\alpha \rightarrow \neg\beta) \Leftrightarrow \neg\alpha$。
- 代换实例：用命题公式代换重言式中的命题变元，结果仍为重言式。
- 置换定理：若$P \Leftrightarrow Q$，$P$是$\alpha$的子公式，将$\alpha$中$P$换为$Q$得$\beta$，则$\alpha \Leftrightarrow \beta$。

### 6. 范式
- 文字：命题变元或其否定。
- 析取式（子句）：有限个文字的析取；合取式（短语）：有限个文字的合取。
- 析取范式：有限个合取式的析取（$\alpha_1 \lor \alpha_2 \lor \dots \lor \alpha_n$，$\alpha_i$为合取式）。
- 合取范式：有限个析取式的合取（$\alpha_1 \land \alpha_2 \land \dots \land \alpha_n$，$\alpha_i$为析取式）。
- 范式存在定理：任意命题公式都存在与其等价的析取范式和合取范式。
- 求范式步骤：
  1. 消去$\rightarrow$、$\leftrightarrow$：$\alpha \rightarrow \beta \Leftrightarrow \neg\alpha \lor \beta$、$\alpha \leftrightarrow \beta \Leftrightarrow (\alpha \land \beta) \lor (\neg\alpha \land \neg\beta)$；
  2. 否定词深入：利用德摩根律和双重否定律，使$\neg$只作用于命题变元；
  3. 分配律化简：析取范式用$\land$对$\lor$分配，合取范式用$\lor$对$\land$分配。

### 7. 主范式
- 极小项：n个命题变元的合取式，每个变元及其否定仅出现一次，记为$m_i$（$i$为二进制成真指派对应的十进制数）。
- 极大项：n个命题变元的析取式，每个变元及其否定仅出现一次，记为$M_i$（$i$为二进制成假指派对应的十进制数）。
- 主析取范式：仅由极小项构成的析取范式（矛盾式无主析取范式，重言式含所有极小项）。
- 主合取范式：仅由极大项构成的合取范式（重言式无主合取范式，矛盾式含所有极大项）。
- 主范式性质：
  1. 任意公式的主析取/主合取范式唯一；
  2. 主析取与主合取范式互补（极小项与极大项互为否定）。

### 8. 联结词完备集
- 完备集定义：任一真值函数可由该集合中的联结词表示。
- 常用完备集：
  - $\{\neg, \land, \lor\}$
  - $\{\neg, \land\}$、$\{\neg, \lor\}$、$\{\neg, \rightarrow\}$
  - 与非式（$P \uparrow Q \Leftrightarrow \neg(P \land Q)$）、或非式（$P \downarrow Q \Leftrightarrow \neg(P \lor Q)$）单独构成完备集。

### 9. 命题逻辑推理
- 推理形式：$\alpha_1 \land \alpha_2 \land \dots \land \alpha_n \Rightarrow \beta$，当且仅当$\alpha_1 \land \alpha_2 \land \dots \land \alpha_n \rightarrow \beta$为重言式。
- 推理定律（重言蕴含式）：
  1. 简化规则：$\alpha \land \beta \Rightarrow \alpha$、$\alpha \land \beta \Rightarrow \beta$；
  2. 附加规则：$\alpha \Rightarrow \alpha \lor \beta$、$\beta \Rightarrow \alpha \lor \beta$；
  3. 假言推理：$\alpha \land (\alpha \rightarrow \beta) \Rightarrow \beta$；
  4. 拒取式：$\neg\beta \land (\alpha \rightarrow \beta) \Rightarrow \neg\alpha$；
  5. 假言三段论：$(\alpha \rightarrow \beta) \land (\beta \rightarrow \gamma) \Rightarrow \alpha \rightarrow \gamma$；
  6. 析取三段论：$\alpha \lor \beta \land \neg\beta \Rightarrow \alpha$；
  7. 二难推理：$(\alpha \rightarrow \gamma) \land (\beta \rightarrow \gamma) \land (\alpha \lor \beta) \Rightarrow \gamma$；
  8. 合取引入：$\alpha, \beta \Rightarrow \alpha \land \beta$。
- 推理方法：
  1. 直接证明：利用前提和推理定律逐步推导结论；
  2. CP规则（条件证明）：若要证$\alpha \Rightarrow \beta \rightarrow \gamma$，可将$\beta$作为附加前提证$\alpha \land \beta \Rightarrow \gamma$；
  3. 反证法（归谬法）：若要证$\alpha \Rightarrow \beta$，可证$\alpha \land \neg\beta$为矛盾式。

## 二、谓词逻辑基础
### 1. 谓词逻辑的基本概念
- 个体词：独立存在的客体（个体常量$a,b,c$；个体变元$x,y,z$）。
- 个体域：个体变元的取值范围（全总个体域：默认包含所有客体）。
- 谓词：刻画个体性质或关系的词（n元谓词$P(x_1,x_2,\dots,x_n)$，0元谓词对应命题）。
- 函词（个体函数）：从个体域到个体域的映射（$f(x_1,x_2,\dots,x_n)$，如“$x$的父亲”记为$f(x)$）。
- 量词：
  1. 全称量词$\forall$：“所有”“任意”，$\forall xA(x)$表示个体域中所有$x$满足$A(x)$；
  2. 存在量词$\exists$：“存在”“至少一个”，$\exists xA(x)$表示个体域中存在$x$满足$A(x)$；
  3. 存在唯一量词$\exists!$：“存在唯一$x$满足$A(x)$”，$\exists!xA(x) \Leftrightarrow \exists x(A(x) \land \forall y(x \neq y \rightarrow \neg A(y)))$。

### 2. 特性谓词的使用（全总个体域下）
- 全称量词$\forall x$：特性谓词作为蕴涵式前件（$\forall x(M(x) \rightarrow A(x))$，$M(x)$为$x$是某类个体）；
    - 对所有 $x$，如果 $x$ 属于论域 $M$（满足特性谓词），则 $x$ 具有性质 $A$ 。

- 存在量词$\exists x$：特性谓词作为合取式项（$\exists x(M(x) \land A(x))$）。
    - 存在某个 $x$，它既属于论域 $M$（满足特性谓词），又具有性质 $A$。


### 3. 谓词公式的定义
- 项的定义：
  1. 个体常量、个体变元是项；
  2. 若$f$是n元函词，$t_1,t_2,\dots,t_n$是项，则$f(t_1,t_2,\dots,t_n)$是项。
- 原子公式：若$P$是n元谓词，$t_1,t_2,\dots,t_n$是项，则$P(t_1,t_2,\dots,t_n)$是原子公式。
- 合式公式：
  1. 原子公式是合式公式；
  2. 若$\alpha$、$\beta$是合式公式，则$\neg\alpha$、$\alpha \land \beta$、$\alpha \lor \beta$、$\alpha \rightarrow \beta$、$\alpha \leftrightarrow \beta$是合式公式；
  3. 若$\alpha$是合式公式，$x$是个体变元，则$\forall x\alpha$、$\exists x\alpha$是合式公式；
  4. 仅由有限次上述规则形成的符号串是合式公式。

### 4. 约束变元与自由变元
- 约束出现：变元在量词辖域内的出现（受量词约束）；
- 自由出现：变元非约束的出现；
- 约束变元改名规则：将量词指导变元及辖域内所有同名约束变元替换为新变元（新变元不在辖域内出现）；
- 自由变元代入规则：将公式中所有同名自由变元替换为新变元（新变元不在公式中出现）。

### 5. 谓词公式的解释与类型
- 解释$I$的构成：
  1. 非空个体域$D$；
  2. 个体常量指定$D$中的元素；
  3. n元函词指定$D^n \rightarrow D$的函数；
  4. n元谓词指定$D^n \rightarrow \{0,1\}$的谓词。
- 公式类型：
  1. 永真式（逻辑有效式）：所有解释下为真；
  2. 永假式（矛盾式）：所有解释下为假；
  3. 可满足式：存在至少一个解释下为真。
- 注：谓词逻辑的永真/永假判定不可解（个体域可无穷）。

### 6. 谓词逻辑等值式
- 命题公式推广：命题逻辑等值式的代换实例（如$\forall xA(x) \Leftrightarrow \neg\neg\forall xA(x)$）。
- 量词转换律：
  1. $\neg\forall xA(x) \Leftrightarrow \exists x\neg A(x)$；
  2. $\neg\exists xA(x) \Leftrightarrow \forall x\neg A(x)$。
- 量词辖域收缩与扩张律（$B$不含$x$）：
  1. $\forall x(A(x) \lor B) \Leftrightarrow \forall xA(x) \lor B$；$\forall x(A(x) \land B) \Leftrightarrow \forall xA(x) \land B$；
  2. $\forall x(A(x) \rightarrow B) \Leftrightarrow \exists xA(x) \rightarrow B$；$\forall x(B \rightarrow A(x)) \Leftrightarrow B \rightarrow \forall xA(x)$；
  3. $\exists x(A(x) \lor B) \Leftrightarrow \exists xA(x) \lor B$；$\exists x(A(x) \land B) \Leftrightarrow \exists xA(x) \land B$；
  4. $\exists x(A(x) \rightarrow B) \Leftrightarrow \forall xA(x) \rightarrow B$；$\exists x(B \rightarrow A(x)) \Leftrightarrow B \rightarrow \exists xA(x)$。
- 量词分配律：
  1. $\forall x(A(x) \land B(x)) \Leftrightarrow \forall xA(x) \land \forall xB(x)$；
  2. $\exists x(A(x) \lor B(x)) \Leftrightarrow \exists xA(x) \lor \exists xB(x)$。
- 多量词等值式（全称量词可交换，存在量词可交换）：
  1. $\forall x\forall yA(x,y) \Leftrightarrow \forall y\forall xA(x,y)$；
  2. $\exists x\exists yA(x,y) \Leftrightarrow \exists y\exists xA(x,y)$。

### 7. 前束范式
- 定义：量词均在公式前端，辖域延伸至公式末端（$Q_1x_1Q_2x_2\dots Q_kx_kB$，$Q_i$为$\forall/\exists$，$B$不含量词）。
- 求前束范式步骤：
  1. 消去$\rightarrow$、$\leftrightarrow$；
  2. 否定词深入（利用量词转换律）；
  3. 约束变元改名（避免变元冲突）；
  4. 量词前移（利用辖域收缩与扩张律）。
- 前束合取/析取范式：前束范式的母式$B$为合取/析取范式。

### 8. Skolem范式
- 定义：不含存在量词的前束范式（仅含全称量词）。
- 转换步骤：
  1. 先化为前束合取范式；
  2. 消去存在量词：
     - 存在量词不在全称量词辖域内：用新常量（Skolem常量）替换；
     - 存在量词在全称量词$\forall x_1,\forall x_2,\dots,\forall x_n$辖域内：用Skolem函数$f(x_1,x_2,\dots,x_n)$替换。
- 性质：原公式与Skolem范式可满足性等价（恒假性等价），但不等价。

### 9. 谓词逻辑推理
- 推理形式：$\alpha_1 \land \alpha_2 \land \dots \land \alpha_k \Rightarrow \beta$，当且仅当$\alpha_1 \land \alpha_2 \land \dots \land \alpha_k \rightarrow \beta$为永真式。
- 推理定律：
  1. 命题推理定律的代换实例（如$\forall xA(x) \land \forall yB(y) \Rightarrow \forall xA(x)$）；
  2. 量词相关推理定律：
     - $\forall xA(x) \Rightarrow \exists xA(x)$；
     - $\forall xA(x) \lor \forall xB(x) \Rightarrow \forall x(A(x) \lor B(x))$；
     - $\exists x(A(x) \land B(x)) \Rightarrow \exists xA(x) \land \exists xB(x)$；
     - $\forall x(A(x) \rightarrow B(x)) \Rightarrow \forall xA(x) \rightarrow \forall xB(x)$；
     - $\forall x(A(x) \rightarrow B(x)) \Rightarrow \exists xA(x) \rightarrow \exists xB(x)$。
- 谓词特有的推理规则：
  1. 全称量词消去规则（US）：
     - $\forall xA(x) \Rightarrow A(y)$（$y$不在$A(x)$中约束出现）；
     - $\forall xA(x) \Rightarrow A(c)$（$c$为个体常量）；
     - 条件：$x$是$A(x)$的自由变元，替换需覆盖所有自由出现的$x$。
  2. 全称量词引入规则（UG）：
     - $A(y) \Rightarrow \forall xA(x)$；
     - 条件：$y$在$A(y)$中自由出现且任意$y$使$A(y)$为真，$x$不在$A(y)$中出现，$y$不在前提中自由出现。
  3. 存在量词消去规则（ES）：
     - $\exists xA(x) \Rightarrow A(c)$；
     - 条件：$c$是新的个体常量（不在前面公式中出现），$c$不在$A(x)$中出现，$A(x)$中自由变元仅$x$。
  4. 存在量词引入规则（EG）：
     - $A(c) \Rightarrow \exists xA(x)$；$A(y) \Rightarrow \exists xA(x)$；
     - 条件：$x$不在$A(c)/A(y)$中出现，替换需覆盖$c/y$的所有出现。
- 推理方法：直接证明、CP规则、反证法（与命题逻辑一致，需结合谓词推理规则）。

### 10. 典型推理实例
- 苏格拉底三段论：
  前提：$\forall x(F(x) \rightarrow G(x))$（人都是要死的），$F(a)$（苏格拉底是人）；
  结论：$G(a)$（苏格拉底是要死的）；
  证明：① $F(a)$（P）；② $\forall x(F(x) \rightarrow G(x))$（P）；③ $F(a) \rightarrow G(a)$（US，②）；④ $G(a)$（T，①③，假言推理）。
- 多量词推理（如$\forall x\forall yA(x,y) \Rightarrow \exists y\forall xA(x,y)$）。

# 数理逻辑解答题答题过程规范（附例题模板）
核心原则：**步骤分点化、依据明确化、符号标准化**，不管是命题逻辑还是谓词逻辑，都遵循“审题翻译→推导过程→结论总结”的三段式结构，每一步推导都必须标注依据，让阅卷人清晰看到你的思路。


## 一、通用答题框架（所有题型适用）
### 1. 审题与翻译（第一步必做）
- 命题逻辑：提取原子命题，用符号（P、Q、R…）表示，明确复合命题的联结词，写出前提和结论的符号化形式。
- 谓词逻辑：确定个体、谓词、量词，明确个体域（默认全总个体域），用特性谓词限制个体范围，写出前提和结论的符号化形式（注意全称量词配蕴涵→，存在量词配合取∧）。
- 要求：符号定义清晰，不遗漏前提条件，结论明确标注。

### 2. 推导过程（核心环节）
- 按“序号+公式+依据”的格式书写，每一步只推一个结论，不跳步。
- 依据必须具体，不能只写“等值演算”“推理规则”，要写清具体名称（如“德摩根律”“US规则”“假言推理”）。
- 常用依据分类：
  - 等值式：标注具体定律（如双重否定律、德摩根律、蕴含等值式等）；
  - 推理规则：命题逻辑（P、T、I、E、CP、反证法），谓词逻辑（US、UG、ES、EG）；
  - 前提引入：直接标注“P”（Premise）；
  - 结论引用：标注“T+上一步序号+依据”（True+推导依据）。

### 3. 结论总结
- 明确写出最终结论，呼应题目要求（如“因此推理有效”“故该公式为重言式”“所以结论成立”）。


## 二、分题型答题模板（结合PPT例题）
### 题型1：命题逻辑推理证明题（直接证明/CP规则/反证法）
#### 模板（以直接证明为例）
**题目**：前提：$A \lor B, B \rightarrow C, A \rightarrow D, \neg D$；结论：$C \land (A \lor B)$  

**答题过程**：

1. 符号定义（已明确可省略）：$A$：XXX，$B$：XXX，$C$：XXX，$D$：XXX
2. 前提符号化：$P_1: A \lor B, P_2: B \rightarrow C, P_3: A \rightarrow D, P_4: \neg D$；结论：$C \land (A \lor B)$
3. 推导过程：
   - (1) $A \rightarrow D$          P（前提引入）
   - (2) $\neg D$              P（前提引入）
   - (3) $\neg A$             T,(1),(2),I（拒取式）
   - (4) $A \lor B$            P（前提引入）
   - (5) $B$                  T,(3),(4),I（析取三段论）
   - (6) $B \rightarrow C$     P（前提引入）
   - (7) $C$                  T,(5),(6),I（假言推理）
   - (8) $C \land (A \lor B)$  T,(4),(7),I（合取引入）
4. 结论：由上述推导可知，结论$C \land (A \lor B)$是前提的有效结论，推理成立。

#### 补充：CP规则模板（结论为蕴涵式时用）
**题目**：前提：$P \lor Q, R \rightarrow \neg P$；结论：$\neg Q \rightarrow \neg R$  

**推导过程**：

1. 符号定义：$P$：逻辑学难学，$Q$：多数学生喜欢，$R$：数学容易学
2. 前提：$P \lor Q, R \rightarrow \neg P$；结论：$\neg Q \rightarrow \neg R$
3. 推导过程：
   - (1) $\neg Q$            P（附加前提，CP规则引入）
   - (2) $P \lor Q$          P（前提引入）
   - (3) $P$                T,(1),(2),I（析取三段论）
   - (4) $R \rightarrow \neg P$  P（前提引入）
   - (5) $\neg R$            T,(3),(4),I（拒取式）
   - (6) $\neg Q \rightarrow \neg R$  CP,(1),(5)（CP规则消去附加前提）
4. 结论：故$\neg Q \rightarrow \neg R$成立，推理有效。

#### 补充：反证法模板（结论否定易推导时用）
**题目**：前提：$P \rightarrow \neg Q, Q \lor \neg R, R \land \neg S$；结论：$\neg P$  

**推导过程**：

1. 前提：$P \rightarrow \neg Q, Q \lor \neg R, R \land \neg S$；结论：$\neg P$
2. 假设：$\neg (\neg P)$（反证法引入否定结论）
3. 推导过程：
   - (1) $\neg (\neg P)$      P（附加前提，反证法假设）
   - (2) $P$                T,(1),E（双重否定律）
   - (3) $P \rightarrow \neg Q$  P（前提引入）
   - (4) $\neg Q$            T,(2),(3),I（假言推理）
   - (5) $Q \lor \neg R$      P（前提引入）
   - (6) $\neg R$            T,(4),(5),I（析取三段论）
   - (7) $R \land \neg S$    P（前提引入）
   - (8) $R$                T,(7),I（简化规则）
   - (9) $R \land \neg R$    T,(6),(8),I（合取引入），矛盾
4. 结论：假设不成立，故原结论$\neg P$成立。


### 题型2：谓词逻辑推理证明题（含量词规则）
#### 核心注意：US/UG/ES/EG规则必须严格遵守条件，标注时写清规则名称+序号
**题目**：苏格拉底三段论：前提：所有人都是要死的，苏格拉底是人；结论：苏格拉底是要死的 

**答题过程**：
1. 符号定义：
   - 个体域：全总个体域
   - 谓词：$F(x)$：$x$是人，$G(x)$：$x$是要死的
   - 个体常量：$a$：苏格拉底
2. 符号化：
   - 前提：$P_1: \forall x(F(x) \rightarrow G(x)), P_2: F(a)$
   - 结论：$G(a)$
3. 推导过程：
   - (1) $F(a)$              P（前提引入）
   - (2) $\forall x(F(x) \rightarrow G(x))$  P（前提引入）
   - (3) $F(a) \rightarrow G(a)$  T,(2),US（全称量词消去规则）
   - (4) $G(a)$              T,(1),(3),I（假言推理）
4. 结论：因此苏格拉底是要死的，推理有效。

#### 谓词逻辑易错点标注：
- ES规则：两次使用时，个体常量不能重复（如第一次用$c$，第二次用$d$）；
- UG规则：被推广的变元不能在前提中自由出现；
- EG规则：替换个体的变元不能在公式中已出现（如$P(x) \rightarrow Q(c)$，EG后为$\exists y(P(x) \rightarrow Q(y))$，不能用$x$）。


### 题型3：命题公式类型判定（重言式/矛盾式/可满足式）
#### 模板（真值表法/等值演算法）
**题目**：判定公式$(P \rightarrow Q) \land (P \land \neg Q)$的类型  
**答题过程（等值演算法）**：
1. 公式：$A = (P \rightarrow Q) \land (P \land \neg Q)$
2. 等值演算过程：
   - (1) $(P \rightarrow Q) \land (P \land \neg Q)$  原式
   - (2) $(\neg P \lor Q) \land (P \land \neg Q)$  T,(1),E（蕴含等值式）
   - (3) $\neg P \land P \land \neg Q \lor Q \land P \land \neg Q$  T,(2),E（分配律）
   - (4) $0 \land \neg Q \lor P \land 0$  T,(3),E（矛盾律）
   - (5) $0 \lor 0$  T,(4),E（零一律）
   - (6) $0$  T,(5),E（零一律）
3. 结论：该公式等值于矛盾式$0$，故为永假式（矛盾式）。


### 题型4：谓词公式前束范式/主范式求解
#### 前束范式模板
**题目**：将公式$\forall x \forall y(\exists z(P(x,z) \land P(y,z)) \rightarrow \exists zQ(x,y,z))$化为前束范式  
**答题过程**：
1. 原式：$\forall x \forall y(\exists z(P(x,z) \land P(y,z)) \rightarrow \exists zQ(x,y,z))$
2. 推导过程：
   - (1) $\forall x \forall y(\neg \exists z(P(x,z) \land P(y,z)) \lor \exists zQ(x,y,z))$  T,原式,E（蕴含等值式：$A \rightarrow B \Leftrightarrow \neg A \lor B$）
   - (2) $\forall x \forall y(\forall z(\neg P(x,z) \lor \neg P(y,z)) \lor \exists zQ(x,y,z))$  T,(1),E（量词转换律：$\neg \exists xA(x) \Leftrightarrow \forall x\neg A(x)$）
   - (3) $\forall x \forall y(\forall z(\neg P(x,z) \lor \neg P(y,z)) \lor \exists uQ(x,y,u))$  T,(2),E（约束变元改名：避免$z$重复）
   - (4) $\forall x \forall y \forall z \exists u(\neg P(x,z) \lor \neg P(y,z) \lor Q(x,y,u))$  T,(3),E（量词前移：扩大量词辖域）
3. 结论：该公式的前束范式为$\forall x \forall y \forall z \exists u(\neg P(x,z) \lor \neg P(y,z) \lor Q(x,y,u))$。


## 三、必背依据清单（标注时直接用）
### 1. 命题逻辑等值式（常用）
- 双重否定律：$A \Leftrightarrow \neg \neg A$
- 德摩根律：$\neg (A \lor B) \Leftrightarrow \neg A \land \neg B$；$\neg (A \land B) \Leftrightarrow \neg A \lor \neg B$
- 蕴含等值式：$A \rightarrow B \Leftrightarrow \neg A \lor B$
- 假言易位：$A \rightarrow B \Leftrightarrow \neg B \rightarrow \neg A$
- 分配律：$A \lor (B \land C) \Leftrightarrow (A \lor B) \land (A \lor C)$；$A \land (B \lor C) \Leftrightarrow (A \land B) \lor (A \land C)$

### 2. 命题逻辑推理定律（常用）
- 假言推理：$(A \rightarrow B) \land A \Rightarrow B$
- 拒取式：$(A \rightarrow B) \land \neg B \Rightarrow \neg A$
- 析取三段论：$(A \lor B) \land \neg B \Rightarrow A$
- 假言三段论：$(A \rightarrow B) \land (B \rightarrow C) \Rightarrow A \rightarrow C$
- 合取引入：$A, B \Rightarrow A \land B$

### 3. 谓词逻辑规则
- US（全称消去）：$\forall xA(x) \Rightarrow A(y)$ 或 $\forall xA(x) \Rightarrow A(c)$
- UG（全称引入）：$A(y) \Rightarrow \forall xA(x)$（$y$任意）
- ES（存在消去）：$\exists xA(x) \Rightarrow A(c)$（$c$为新常量）
- EG（存在引入）：$A(c) \Rightarrow \exists xA(x)$ 或 $A(y) \Rightarrow \exists xA(x)$（$x$未出现）


## 四、答题易错点提醒
1. 符号书写：联结词$\neg、\land、\lor、\rightarrow、\leftrightarrow$，量词$\forall、\exists$要规范，不要手写简写。
2. 依据标注：避免“跳步标注”，如从$(A \lor B) \land \neg A$直接到$B$，必须标注“析取三段论”，不能只写“I”。
3. 谓词逻辑：特性谓词的使用（全称配→，存在配合取），量词顺序不能随意调换。
4. 反证法/CP规则：必须明确标注“附加前提”，最后消去时标注“CP”或“矛盾，假设不成立”。

要不要我帮你整理一份**常用依据速查手册**？包含所有等值式、推理定律、量词规则的简化标注方式，方便你答题时直接查阅。