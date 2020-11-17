//
//  GLHomeViewController.m
//  LearnOpenGL
//
//  Created by 王江 on 2020/11/5.
//

#import "GLHomeViewController.h"
#import "GLEffectRenderViewController.h"

@interface GLHomeViewController ()

@end

@implementation GLHomeViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self.tableView registerClass:[UITableViewCell class] forCellReuseIdentifier:@"UITableViewCell"];
}

#pragma mark Data Source & Delegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return GLLearnCasesCount;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"UITableViewCell"];
    GLLearnCases glcase = (GLLearnCases)(indexPath.row);
    cell.textLabel.text = [self nameForCase:glcase];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.item >= GLLearnCasesCount) { return; }
    GLLearnCases glcase = (GLLearnCases)(indexPath.row);
    GLEffectRenderViewController *renderVC = [[GLEffectRenderViewController alloc] initWithType:glcase];
    [self.navigationController pushViewController:renderVC animated:YES];
}

#pragma mark Data
- (NSString *)nameForCase:(GLLearnCases)glCase {
    switch (glCase) {
        case GLLearnCasesTriangle: {
            return @"Triangle";
            break;
        }
        case GLLearnCasesRectangle: {
            return @"Rectangle";
            break;
        }
        case GLLearnCasesTexure: {
            return @"Texture";
            break;
        }
        default:
            break;
    }
    return @"Undefined";
}

@end
