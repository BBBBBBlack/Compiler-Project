## 产生式

- program → A basic id ( ) block 
- A → ε 
- block → { decls stmts } 
- stmts → ε 
- decls → decl decls 
- decls → ε 
- decl → type id ; 
- type → basic B array 
- B → ε 
- array → ε 
- array → [ num ] array 
- basic → float 
- basic → int 
- basic → real 
- START → program 

## FA Graph

```mermaid
	graph LR
	node0("<div>I0:<br>A → ε ·<br>program → ·A basic id ( ) block <br>START → ·program <br></div>")
	node0--> |"A"| node2
	node0--> |"program"| node1
	node1("<div>I1:<br>START → program ·<br></div>")
	node2("<div>I2:<br>basic → ·real <br>basic → ·int <br>basic → ·float <br>program → A ·basic id ( ) block <br></div>")
	node2--> |"float"| node6
	node2--> |"real"| node5
	node2--> |"int"| node4
	node2--> |"basic"| node3
	node3("<div>I3:<br>program → A basic ·id ( ) block <br></div>")
	node3--> |"id"| node7
	node4("<div>I4:<br>basic → int ·<br></div>")
	node5("<div>I5:<br>basic → real ·<br></div>")
	node6("<div>I6:<br>basic → float ·<br></div>")
	node7("<div>I7:<br>program → A basic id ·( ) block <br></div>")
	node7--> |"("| node8
	node8("<div>I8:<br>program → A basic id ( ·) block <br></div>")
	node8--> |")"| node9
	node9("<div>I9:<br>block → ·{ decls stmts } <br>program → A basic id ( ) ·block <br></div>")
	node9--> |"{"| node11
	node9--> |"block"| node10
	node10("<div>I10:<br>program → A basic id ( ) block ·<br></div>")
	node11("<div>I11:<br>basic → ·int <br>basic → ·float <br>decl → ·type id ; <br>type → ·basic B array <br>decls → ε ·<br>decls → ·decl decls <br>basic → ·real <br>block → { ·decls stmts } <br></div>")
	node11--> |"decls"| node14
	node11--> |"float"| node6
	node11--> |"real"| node5
	node11--> |"int"| node4
	node11--> |"decl"| node15
	node11--> |"type"| node13
	node11--> |"basic"| node12
	node12("<div>I12:<br>B → ε ·<br>type → basic ·B array <br></div>")
	node12--> |"B"| node16
	node13("<div>I13:<br>decl → type ·id ; <br></div>")
	node13--> |"id"| node17
	node14("<div>I14:<br>stmts → ε ·<br>block → { decls ·stmts } <br></div>")
	node14--> |"stmts"| node18
	node15("<div>I15:<br>basic → ·real <br>basic → ·int <br>basic → ·float <br>type → ·basic B array <br>decls → ε ·<br>decls → ·decl decls <br>decl → ·type id ; <br>decls → decl ·decls <br></div>")
	node15--> |"decls"| node19
	node15--> |"float"| node6
	node15--> |"real"| node5
	node15--> |"int"| node4
	node15--> |"decl"| node15
	node15--> |"type"| node13
	node15--> |"basic"| node12
	node16("<div>I16:<br>array → ·[ num ] array <br>array → ε ·<br>type → basic B ·array <br></div>")
	node16--> |"["| node21
	node16--> |"array"| node20
	node17("<div>I17:<br>decl → type id ·; <br></div>")
	node17--> |";"| node22
	node18("<div>I18:<br>block → { decls stmts ·} <br></div>")
	node18--> |"}"| node23
	node19("<div>I19:<br>decls → decl decls ·<br></div>")
	node20("<div>I20:<br>type → basic B array ·<br></div>")
	node21("<div>I21:<br>array → [ ·num ] array <br></div>")
	node21--> |"num"| node24
	node22("<div>I22:<br>decl → type id ; ·<br></div>")
	node23("<div>I23:<br>block → { decls stmts } ·<br></div>")
	node24("<div>I24:<br>array → [ num ·] array <br></div>")
	node24--> |"]"| node25
	node25("<div>I25:<br>array → ·[ num ] array <br>array → ε ·<br>array → [ num ] ·array <br></div>")
	node25--> |"["| node21
	node25--> |"array"| node26
	node26("<div>I26:<br>array → [ num ] array ·<br></div>")
```
