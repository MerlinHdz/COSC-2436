
# A Link Based Implementation of the ADT Queue

A link-based implementation of a queue uses a chain of linked nodes, much like the other  
link-based implementations we've seen. The queue presents a **challenge**, since we  
must not only be able to remove entries from its front but also add them to its back. Removing  
a node from the beginning of a linked chain is easy, but to add a new node to the chain's end, we  
need a pointer to the chain's last node.  

One way to accomplish this is to begin at the first node and traverse the chain until we reach  
the last one. A much more efficient approach uses a **tail pointer** to reference the end of the chain  
-- just as the head pointer references the beginning of the chain.  

Like the head pointer **frontPtr**, **backPtr** is external to the chain.