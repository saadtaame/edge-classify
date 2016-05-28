# edge-classify
A demonstration of how DFS can be used to classify edges in a directed graph.

The edges of a directed graph can be classified into three types with respect to a spanning tree computed by DFS:
* A forward edge goes from a node to one of its decendants in the DFS tree
* A back edge goes from a node to one of its ancestors in the DFS tree
* A cross edges is neither of the above two

Sometimes the edges in the tree are assigned their own class (called tree edges). The algorithm can be easily modified to account for this change.
