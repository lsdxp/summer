boxes=[1,2,1,2]
melons=[3,2,1]

boxes=[2,1,2,2]
melons=[2,3,2]

#
boxes=[4,3,2,3,1,3,2,4,2]
melons=[1,2,1,3,4,3,2,4]

def  melon_count(boxes, melons):
    count=0
    boxes_cnt=0
    if(melons[0]>max(boxes)):
        melons.pop(0)
    for x in range(len(melons)):
        while(len(boxes)>boxes_cnt):
            if(melons[x]<=boxes[boxes_cnt]):
                count+=1
                boxes_cnt+=1;
                break
            boxes_cnt+=1;
    return count

