## 产生式

- E → E * E 
- E → E + E 
- E → digit 
- START → E 

## FA Graph

```mermaid
	graph LR
	node0("<div>I0:<br>E → ·digit <br>E → ·E + E <br>E → ·E * E <br>START → ·E <br></div>")
	node0--> |"digit"| node2
	node0--> |"E"| node1
	node1("<div>I1:<br>START → E ·<br>E → E ·* E <br>E → E ·+ E <br></div>")
	node1--> |"+"| node4
	node1--> |"*"| node3
	node2("<div>I2:<br>E → digit ·<br></div>")
	node3("<div>I3:<br>E → ·digit <br>E → ·E + E <br>E → ·E * E <br>E → E * ·E <br></div>")
	node3--> |"digit"| node2
	node3--> |"E"| node5
	node4("<div>I4:<br>E → ·digit <br>E → ·E + E <br>E → ·E * E <br>E → E + ·E <br></div>")
	node4--> |"digit"| node2
	node4--> |"E"| node6
	node5("<div>I5:<br>E → E * E ·<br>E → E ·* E <br>E → E ·+ E <br></div>")
	node5--> |"+"| node4
	node5--> |"*"| node3
	node6("<div>I6:<br>E → E + E ·<br>E → E ·* E <br>E → E ·+ E <br></div>")
	node6--> |"+"| node4
	node6--> |"*"| node3
```
